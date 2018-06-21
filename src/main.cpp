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

    StateMachine stm(clock);

    while (true) {

        switch (stm.getState()) {

        case TimeManagerStates::MAIN_MENU:
            stm.mainMenu();
            break;

        case TimeManagerStates::SET_TIME:
            stm.setTime();
            break;

        case TimeManagerStates::TIMER_SELECT:
            stm.timerSelect();
            break;

        case TimeManagerStates::ALARM_SELECT:
            stm.alarmSelect();
            break;

        case TimeManagerStates::TIMER:
            stm.timerMenu(timerCounter);
            break;

        case TimeManagerStates::ALARM:
            stm.alarmMenu(alarmCounter);
            break;

        case TimeManagerStates::SET_ALARM:
            hwlib::cout << "Setting an alarm" << hwlib::endl;
            break;
        }
    }
    return 0;
}