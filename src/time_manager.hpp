/**
 * @file
 * @brief     HPP file for the TimeManager class to control the DS3231 RTC
 * module
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#ifndef TIME_MANAGER_HPP
#define TIME_MANAGER_HPP

#include <array>
#include <cstdint>

#include "bcd_conversion.hpp"
//#include "object_pool.hpp"
#include "rtc_time.hpp"
#include "wrap-hwlib.hpp"

namespace Time {
class TimeManager {
  private:
    hwlib::pin_oc &scl;
    hwlib::pin_oc &sda;
    hwlib::i2c_bus_bit_banged_scl_sda realTimeClock;

    RTCTime alarm;
    bool alarmRunning = false;

    // RTCTime timer;
    static const uint16_t TIMER_AMOUNT = 5;
    std::array<RTCTime, TIMER_AMOUNT> timerArray = {{getTime()}};
    std::array<bool, TIMER_AMOUNT> activeTimers = {{false}};
    // bool timerRunning = false;

  public:
    /**
     * @brief Default constructor.
     *
     * Default constructor of the TimeManager class.
     *
     * @param[in]     scl    The clock pin for the i2c connection.
     * @param[in]     sda    The data pin for the i2c connection.
     */
    TimeManager(hwlib::pin_oc &scl, hwlib::pin_oc &sda);

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

    /**
     * @brief Set the alarm.
     *
     * Set the alarm time to a new time.
     *
     * @param[in]     alarmId     Number of alarm. (Ignored for now)
     * @param[in]     newAlarm    A RTCTime struct with the new alarm.
     */
    void setAlarm(int alarmId, RTCTime newAlarm);

    /**
     * @brief Clear the alarm.
     *
     * Resets the alarm so that is doesn't run anymore.
     *
     * @param[in]     alarmId     Number of alarm. (Ignored for now)
     */
    void clearAlarm(int alarmId);

    /**
     * @brief Set the timer.
     *
     * Set the timer time to the current time on the RTC module.
     *
     * @param[in]     timerId     Number of timer.
     */
    void setTimer(int timerId);

    /**
     * @brief Returns the timer container.
     *
     * Returns the timer container
     *
     * @param[out]     std::array<RTCTime, 5>     Timer array
     */
    std::array<RTCTime, TIMER_AMOUNT> getTimerArray();

    /**
     * @brief Get the elapsed time.
     *
     * Get the elapsed time of the timer since the timer was set.
     *
     * @param[in]     timerId     Number of timer.
     * @return        RTCTime     A RTCTime struct with the elapsed time.
     */
    RTCTime elapsedTime(int timerId);

    /**
     * @brief Resets the timer.
     *
     * Resets the timer to the current time on the RTC module.
     *
     * @param[in]     timerId     Number of timer.
     */
    void resetTimer(int timerId);

    /**
     * @brief Clears the timer.
     *
     * Clears the time so that it is no longer running.
     *
     * @param[in]     timerId     Number of timer.
     */
    void clearTimer(int timerId);

    /**
     * @brief Stops the timer.
     *
     * Stops the timer so that it is no longer running, without clearing the time.
     *
     * @param[in]     timerId     Number of timer.
     */
    void stopTimer(int timerId);
};
} // namespace Time

#endif // TIME_MANAGER_HPP
