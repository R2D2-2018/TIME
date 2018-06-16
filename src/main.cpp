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

    Time::RTCTime temp(43, 32, 21, 1, 14, 5, 19);
    Time::RTCTime temp2(1, 2, 3, 0, 5, 3, 1);

    // hwlib::cout << (temp - temp2) << hwlib::endl;

    clock.setTime(temp);
    auto timers = clock.getTimerArray();
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

        hwlib::cout << "Current time is: \t" << clock.getTime().getTotalSeconds() - temp.getTotalSeconds() << hwlib::endl;

        for (uint16_t i = 0; i < timers.size(); i++) {
            hwlib::cout << (clock.elapsedTime(i).getTotalSeconds()) << '\t';
        }
        hwlib::cout << hwlib::endl;
    }
    // temp.setTotalSeconds(temp.getTotalSeconds());

    /*
     while (true) {
         Time::RTCTime time = clock.getTime();
         hwlib::cout << static_cast<int>(time.getHours()) << ":" << static_cast<int>(time.getMinutes()) << ":"
                     << static_cast<int>(time.getSeconds()) << " - " << static_cast<int>(time.getDayOfTheWeek()) << " "
                     << static_cast<int>(time.getDayOfTheMonth()) << "/" << static_cast<int>(time.getMonth()) << "/"
                     << static_cast<int>(time.getYear()) << hwlib::endl;
         hwlib::wait_ms(100);
     }
     */
    return 0;
}
