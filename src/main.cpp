/**
 * @file
 * @brief     Main file for the TimeManager class to control the DS3231 RTC
 * module
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#include "wrap-hwlib.hpp"

#include "rtc_time.hpp"
#include "time_manager.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto clock = Time::TimeManager(scl, sda);

    auto timersSize = clock.getTimerArraySize();
    uint16_t timerCounter = 0;

    char someInput;
    while (true) {
        hwlib::cin >> someInput;
        if (someInput == 'q') {
            clock.setTimer(timerCounter);
        }
        if (someInput == 'w') {
            clock.resetTimer(timerCounter);
        }
        if (someInput == 'e') {
            clock.clearTimer(timerCounter);
        }

        if (someInput == 'o') {
            if (timerCounter > 0) {
                timerCounter--;
            }
            hwlib::cout << timerCounter + 1 << hwlib::endl;
        }
        if (someInput == 'p') {
            if (timerCounter < 4) {
                timerCounter++;
            }
            hwlib::cout << timerCounter + 1 << hwlib::endl;
        }

        hwlib::cout << "Current second count is: \t" << clock.getTime().getTotalSeconds() << hwlib::endl;

        for (uint16_t i = 0; i < timersSize; i++) {
            hwlib::cout << (clock.elapsedTime(i).getTotalSeconds()) << '\t';
        }
        hwlib::cout << hwlib::endl;
    }
    return 0;
}
