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

    uint16_t alarmCounter = 0;

    uint16_t timerCounter = 0;

    StateMachine STM(clock);

    Time::RTCTime temp(0, 0, 0, 1, 1, 1, 0);
    Time::RTCTime temp2(30, 0, 0, 1, 1, 1, 0);

    hwlib::cout << temp.getTotalSeconds() << '-' << temp2.getTotalSeconds() << '=' << hwlib::endl;

    hwlib::cout << (temp.getTotalSeconds() - temp2.getTotalSeconds()) << hwlib::endl;

    while (true) {
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