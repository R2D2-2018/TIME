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

    Time::StateMachine STM(clock);

    while (true) {
        switch (STM.getState()) {

        case TimeManagerStates::MAIN_MENU:
            STM.mainMenu();
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
            STM.timerMenu();
            break;

        case TimeManagerStates::ALARM:
            STM.alarmMenu();
            break;

        case TimeManagerStates::SET_ALARM:
            STM.setTime();
            break;
        }
    }
    return 0;
}