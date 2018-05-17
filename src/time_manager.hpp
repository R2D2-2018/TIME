/**
 * @file
 * @brief     HPP file for the TimeManager class to control the DS3231 RTC module
 * @author    Jasper Smienk
 * @license   MIT License
 */

#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <cstdint>

#include "wrap-hwlib.hpp"
#include "rtc_time.hpp"
#include "bcd_conversion.hpp"

namespace time {
    class TimeManager {
    private:
        hwlib::target::pin_oc & scl;
        hwlib::target::pin_oc & sda;
        hwlib::i2c_bus_bit_banged_scl_sda realTimeClock;

    public:
        /**
         * @brief Default constructor.
         *
         * Default constructor of the TimeManager class.
         *
         * @param[in]     scl    The clock pin for the i2c connection.
         * @param[in]     sda    The data pin for the i2c connection.
         */
        TimeManager(hwlib::target::pin_oc & scl, hwlib::target::pin_oc & sda);

        /**
         * @brief Get the time.
         * 
         * Get the data from the RTC chip.
         * 
         * @return A RTCTime struct whith data from the RTC chip.
         */
        RTCTime getTime();

        /**
         * @brief Set the time.
         *
         * Set the time on the RTC chip.
         *
         * @param[in]     timeAndDate    A RTCTime struct with the desired date.
         */
        void setTime(RTCTime timeAndDate);
    };
}

#endif // TIME_MANAGER_H
