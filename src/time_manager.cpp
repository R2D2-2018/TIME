/**
 * @file
 * @brief     CPP file for the TimeManager class to control the DS3231 RTC module
 * @author    Jasper Smienk
 * @license   MIT License
 */

#include "time_manager.hpp"

namespace time {
    TimeManager::TimeManager(hwlib::target::pin_oc & scl, hwlib::target::pin_oc & sda):
        scl(scl),
        sda(sda),
        realTimeClock(hwlib::i2c_bus_bit_banged_scl_sda(scl, sda))
    {}


    RTCTime TimeManager::getTime() {
        uint8_t zero[] = {0}; // Todo: Find better way for this.
        realTimeClock.write(0x68, zero, 1); // Set address register to 0.
       
        uint8_t data[7];
        realTimeClock.read(0x68, data, 7);

        RTCTime timeAndDate;
        timeAndDate.set(BCDToDec(data[0]),
                        BCDToDec(data[1]),
                        BCDToDec(data[2]),
                        BCDToDec(data[3]),
                        BCDToDec(data[4]),
                        BCDToDec(data[5]),
                        BCDToDec(data[6]));
        return timeAndDate;
    }

    void TimeManager::setTime(RTCTime timeAndDate) {
        uint8_t data[] = {0, decToBCD(timeAndDate.getSeconds()),
                             decToBCD(timeAndDate.getMinutes()),
                             decToBCD(timeAndDate.getHours()),
                             decToBCD(timeAndDate.getDayOfTheWeek()),
                             decToBCD(timeAndDate.getDayOfTheMonth()),
                             decToBCD(timeAndDate.getMonth()),
                             decToBCD(timeAndDate.getYear())};
        realTimeClock.write(0x68, data, 8);
    }
}
