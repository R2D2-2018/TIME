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
    // clock.setTime(0);

    auto alarmsSize = clock.getAlarmArraySize();
    uint16_t alarmCounter = 0;

    auto timersSize = clock.getTimerArraySize();
    uint16_t timerCounter = 0;

    enum TimeManagerStates timeMngrState;

    timeMngrState = TimeManagerStates::MAIN_MENU;

    char someInput;

    while (true) {
        auto now = clock.getTime();

        switch (timeMngrState) {

        case TimeManagerStates::MAIN_MENU:
            mainMenu(clock, &timeMngrState);
            break;

        case TimeManagerStates::TIMER_SELECT:
            timerSelect(clock, &timeMngrState);
            break;

        case TimeManagerStates::ALARM_SELECT:
            alarmSelect(clock, &timeMngrState);
            break;

        case TimeManagerStates::TIMER:
            timerMenu(clock, &timeMngrState, timerCounter);
            break;

        case TimeManagerStates::ALARM:
            alarmMenu(clock, &timeMngrState, alarmCounter);
            break;

        case TimeManagerStates::SET_ALARM:
            hwlib::cout << "Setting an alarm" << hwlib::endl;
            break;
        }
    }

    //  char someInput;
    //  while (true) {
    //      hwlib::cin >> someInput;
    //      if (someInput == 'q') {
    //          clock.setTimer(timerCounter);
    //      }
    //      if (someInput == 'w') {
    //          clock.resetTimer(timerCounter);
    //      }
    //      if (someInput == 'e') {
    //          clock.clearTimer(timerCounter);
    //      }

    //      if (someInput == 'o') {
    //          if (timerCounter > 0) {
    //              timerCounter--;
    //          }
    //          hwlib::cout << timerCounter + 1 << hwlib::endl;
    //      }
    //      if (someInput == 'p') {
    //          if (timerCounter < 4) {
    //              timerCounter++;
    //          }
    //          hwlib::cout << timerCounter + 1 << hwlib::endl;
    //      }

    //      hwlib::cout << "Current second count is: \t" << clock.getTime().getTotalSeconds() << hwlib::endl;

    //     for (uint16_t i = 0; i < timersSize; i++) {
    //         hwlib::cout << (clock.elapsedTime(i).getTotalSeconds()) << '\t';
    //     }
    //     hwlib::cout << hwlib::endl;
    // }
    return 0;
}
