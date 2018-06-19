/**
 * @file
 * @brief     Main file for the TimeManager class to control the DS3231 RTC
 * module
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#include "wrap-hwlib.hpp"

#include "enumStates.hpp"
#include "rtc_time.hpp"
#include "time_manager.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto clock = Time::TimeManager(scl, sda);
    clock.setTime(0);

    auto alarmsSize = clock.getAlarmArraySize();
    uint16_t alarmCounter = 0;

    auto timersSize = clock.getTimerArraySize();
    uint16_t timerCounter = 0;

    enum timeManagerStates timeManagerState;

    char someInput;

    while (true) {
        auto now = clock.getTime();
        timeManagerState = timeManagerStates::MAIN_MENU;

        switch (timeManagerState) {

        case timeManagerStates::MAIN_MENU:
            hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
            hwlib::cout << "Press 1 to cycle through menu, press 2 to select menu, press 3 to cancel" << hwlib::endl;

            if (clock.getTime() - now >= 60) {
                hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
                now = clock.getTime();
            }

            hwlib::cin >> someInput;

            if (someInput == '1') {
                timeManagerState = timeManagerStates::TIMER_SELECT;
            }
            break;

        case timeManagerStates::TIMER_SELECT:
            hwlib::cout << "Timer menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == '1') {
                timeManagerState = timeManagerStates::ALARM_SELECT;
            }
            if (someInput == '2') {
                timeManagerState = timeManagerStates::TIMER;
            }
            if (someInput == '3') {
                timeManagerState = timeManagerStates::MAIN_MENU;
            }
            break;

        case timeManagerStates::ALARM_SELECT:
            hwlib::cout << "Alarm menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == '1') {
                timeManagerState = timeManagerStates::TIMER_SELECT;
            }
            if (someInput == '2') {
                timeManagerState = timeManagerStates::ALARM;
            }
            if (someInput == '3') {
                timeManagerState = timeManagerStates::MAIN_MENU;
            }
            break;

        case timeManagerStates::TIMER:
            hwlib::cout << "Timer selected. Press 3 to return to main menu" << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == '3') {
                timeManagerState = timeManagerStates::MAIN_MENU;
            }
            break;

        case timeManagerStates::ALARM:
            hwlib::cout << "Alarm selected. Press 3 to return to main menu" << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == '3') {
                timeManagerState = timeManagerStates::MAIN_MENU;
            }
            break;
        }
    }

    // char someInput;
    // while (true) {
    //     hwlib::cin >> someInput;
    //     if (someInput == 'q') {
    //         clock.setTimer(timerCounter);
    //     }
    //     if (someInput == 'w') {
    //         clock.resetTimer(timerCounter);
    //     }
    //     if (someInput == 'e') {
    //         clock.clearTimer(timerCounter);
    //     }

    //     if (someInput == 'o') {
    //         if (timerCounter > 0) {
    //             timerCounter--;
    //         }
    //         hwlib::cout << timerCounter + 1 << hwlib::endl;
    //     }
    //     if (someInput == 'p') {
    //         if (timerCounter < 4) {
    //             timerCounter++;
    //         }
    //         hwlib::cout << timerCounter + 1 << hwlib::endl;
    //     }

    //     hwlib::cout << "Current second count is: \t" << clock.getTime().getTotalSeconds() << hwlib::endl;

    //     for (uint16_t i = 0; i < timersSize; i++) {
    //         hwlib::cout << (clock.elapsedTime(i).getTotalSeconds()) << '\t';
    //     }
    //     hwlib::cout << hwlib::endl;
    // }
    return 0;
}
