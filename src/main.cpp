/**
 * @file
 * @brief     Main file for the TimeManager class to control the DS3231 RTC
 * module
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#include "wrap-hwlib.hpp"

#include "rtc_time.hpp"
#include "state_machine.hpp"
#include "time_manager.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto clock = Time::TimeManager(scl, sda);

    auto alarmsSize = clock.getAlarmArraySize();
    uint16_t alarmCounter = 0;

    auto timersSize = clock.getTimerArraySize();
    uint16_t timerCounter = 0;

    StateMachine STM(clock);

    // Time::RTCTime now(1, 40, 12, 4, 6, 8, 19);
    // hwlib::cout << now.getYear() << hwlib::endl;
    // hwlib::cout << "SETTING TIME: \t";
    // clock.setTime(now);
    // hwlib::cout << "DONE SETTING TIME" << hwlib::endl;

    // hwlib::cout << "DAY OF THE MONTH: \t" << (int)clock.getTime().getDayOfTheMonth() << hwlib::endl;
    // hwlib::cout << "MONTH: \t" << (int)clock.getTime().getMonth() << hwlib::endl;

    while (true) {
        // hwlib::cout << (int)clock.getTime().getYear() << hwlib::endl;
        //' ' << clock.getTime().getMonth() << ' ' << clock.getTime().getDayOfTheMonth()
        //            << ' ' << clock.getTime().getHours() << ' ' << clock.getTime().getMinutes() << hwlib::endl;
        switch (STM.getState()) {

        case TimeManagerStates::MAIN_MENU:
            STM.mainMenu(clock);
            break;

        case TimeManagerStates::SET_TIME:
            STM.setTime();
            break;

        case TimeManagerStates::TIMER_SELECT:
            STM.timerSelect();
            break;

        case TimeManagerStates::ALARM_SELECT:
            STM.alarmSelect();
            break;

        case TimeManagerStates::TIMER:
            STM.timerMenu(timerCounter);
            break;

        case TimeManagerStates::ALARM:
            STM.alarmMenu(alarmCounter);
            break;

        case TimeManagerStates::SET_ALARM:
            hwlib::cout << "Setting an alarm" << hwlib::endl;
            break;
        }
    }
    return 0;
}