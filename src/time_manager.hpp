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
#include "rtc_time.hpp"
#include "wrap-hwlib.hpp"

namespace Time {
class TimeManager {
  private:
    ///< Reference to the Arduino SCL pin (pin 21)
    hwlib::pin_oc &scl;
    ///< Reference to the Arduino SDA pin (pin 22)
    hwlib::pin_oc &sda;
    ///< Bit banged i2c bus object
    hwlib::i2c_bus_bit_banged_scl_sda realTimeClock;

    ///< Maximum number of alarms
    static const uint16_t ALARM_AMOUNT = 5;
    ///< Alarm container, initialised at 0
    std::array<RTCTime, ALARM_AMOUNT> alarmArray = {{getTime()}};
    ///< Container that keeps track of which alarms are active, initalised at false
    std::array<bool, ALARM_AMOUNT> activeAlarms = {{false}};

    ///< Maximum number of timers
    static const uint16_t TIMER_AMOUNT = 5;
    ///< Timer container, initialised at 0
    std::array<RTCTime, TIMER_AMOUNT> timerArray = {{getTime()}};
    ///< Container that keeps track of active timers
    std::array<bool, TIMER_AMOUNT> activeTimers = {{false}};

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
     * @param[in]     alarmId     Number of alarm.
     * @param[in]     newAlarm    A RTCTime struct with the new alarm.
     */
    void setAlarm(int alarmId, RTCTime newAlarm);

    /**
     * @brief Returns the alarm container.
     *
     * Returns the alarm container
     *
     * @return     std::array<RTCTime, ALARM_AMOUNT>  Alarm array
     */
    uint16_t getAlarmArraySize();

    /**
     * @brief Clear the alarm.
     *
     * Resets the alarm so that is doesn't run anymore.
     *
     * @param[in]     alarmId     Number of alarm.
     */
    void clearAlarm(int alarmId);

    /**
     * @brief Checks if an alarm has expired
     *
     * This function checks if an alarm is running (if not it returns false),
     * and if it is, it returns whether or not the current time is equal to
     * or has surpassed the set time for the alarm.
     *
     * @param[in]     alarmId     Number of alarm.
     * @return        bool        Whether or not the alarm has expired
     */
    bool checkAlarm(int alarmId);

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
     * @param[out]     std::array<RTCTime, TIMER_AMOUNT>  Timer array
     */
    uint16_t getTimerArraySize() const;

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

    /**
     * @brief Returns whether a timer is active or not
     *
     * @param[in]       timerId     Numver of timer.
     */
    bool checkActiveTimer(int timerId);

    /**
     * @brief Returns whether an alarm is active or not
     *
     * @param[in]       alarmId     Numver of alarm.
     */
    bool checkActiveAlarm(int alarmId);
};
} // namespace Time

#endif // TIME_MANAGER_HPP
