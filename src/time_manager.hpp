/**
 * @file
 * @brief     HPP file for the TimeManager class to control the DS3231 RTC module
 * @author    Jasper Smienk
 * @license   MIT License
 */

#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "wrap-hwlib.hpp"

class TimeManager {
private:
    hwlib::target::pin_oc & scl;
    hwlib::target::pin_oc & sda;
    hwlib::i2c_bus_bit_banged_scl_sda realTimeClock;

public:
    TimeManager(hwlib::target::pin_oc & scl, hwlib::target::pin_oc & sda);

};

#endif // TIME_MANAGER_H
