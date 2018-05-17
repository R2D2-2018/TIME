/**
 * @file
 * @brief     Main file for the TimeManager class to control the DS3231 RTC module
 * @author    Jasper Smienk
 * @license   MIT License
 */

#include "wrap-hwlib.hpp"

#include "time_manager.hpp"
#include "rtc_time.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto clock = time::TimeManager(scl, sda);

    time::RTCTime temp;
    temp.set(0, 11, 10, 1, 14, 5, 18);
    //clock.setTime(temp);

    while (true) {
        time::RTCTime time = clock.getTime();
        hwlib::cout << static_cast<int>(time.getHours()) << ":"
                    << static_cast<int>(time.getMinutes()) << ":"
                    << static_cast<int>(time.getSeconds()) << " - "
                    << static_cast<int>(time.getDayOfTheWeek()) << " "
                    << static_cast<int>(time.getDayOfTheMonth()) << "/"
                    << static_cast<int>(time.getMonth()) << "/"
                    << static_cast<int>(time.getYear()) << hwlib::endl;
        hwlib::wait_ms(100);
    }
    return 0;
}
