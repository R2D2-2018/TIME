/**
 * @file
 * @brief     HPP file for the RTCTime struct.
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#ifndef RTC_TIME_HPP
#define RTC_TIME_HPP

#include <array>
#include <cstdint>
#include <tuple>
#include <vector>

#include "bcd_conversion.hpp"
#include "wrap-hwlib.hpp"

namespace Time {
struct RTCTime {
  private:
    uint8_t seconds = 0;
    uint8_t minutes = 0;
    uint8_t hours = 0;
    uint8_t dayOfTheWeek = 1;
    uint8_t dayOfTheMonth = 1;
    uint8_t month = 1;
    uint8_t year = 0;

  public:
    /**
     * @brief Default constructor of RTCTime
     */
    RTCTime(){};

    /**
     * @brief Constructor of RTCTime which can set all values
     */
    RTCTime(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek, uint8_t dayOfTheMonth, uint8_t month,
            uint8_t year);

    /**
     * @brief Constructor which uses just 1 value for the total seconds.
     */
    explicit RTCTime(uint64_t totalSeconds);

    /**
     * @brief Get the amount of seconds.
     *
     * Get the amount of seconds in decimal.
     *
     * @return The amount of seconds in decimal.
     */
    uint8_t getSeconds() const;

    /**
     * @brief Get the amount of minutes.
     *
     * Get the amount of minutes in decimal.
     *
     * @return The amount of minutes in decimal.
     */
    uint8_t getMinutes() const;

    /**
     * @brief Get the amount of hours.
     *
     * Get the amount of hours in decimal.
     *
     * @return The amount of hours in decimal.
     */
    uint8_t getHours() const;

    /**
     * @brief Get the day of the week.
     *
     * Get the day of the week in decimal.
     *
     * @return The the day of the week in decimal.
     */
    uint8_t getDayOfTheWeek() const;

    /**
     * @brief Get the day of the month.
     *
     * Get the day of the month in decimal.
     *
     * @return The day of the month in decimal.
     */
    uint8_t getDayOfTheMonth() const;

    /**
     * @brief Get the month number.
     *
     * Get the month in decimal.
     *
     * @return The month in decimal.
     */
    uint8_t getMonth() const;

    /**
     * @brief Get the year number.
     *
     * Get the year in decimal.
     *
     * @return The year in decimal.
     */
    uint8_t getYear() const;

    /**
     * @brief Get the total time in seconds.
     *
     * Get the total time of the whole struct in seconds.
     * 1 minute is 60 seconds, 1 hour is 3600 seconds, etc.
     *
     * @return The total time in seconds.
     */
    uint64_t getTotalSeconds() const;

    /**
     * @brief Set the amount of seconds.
     *
     * Set the amount of seconds in decimal.
     *
     * @param[in]   seconds   The amount of seconds in decimal.
     */
    void setSeconds(uint8_t seconds);

    /**
     * @brief Set the amount of minutes.
     *
     * Set the amount of minutes in decimal.
     *
     * @param[in]   minutes   The amount of minutes in decimal.
     */
    void setMinutes(uint8_t minutes);

    /**
     * @brief Set the amount of hours.
     *
     * Set the amount of hours in decimal.
     *
     * @param[in]   hours   The amount of hours in decimal.
     */
    void setHours(uint8_t hours);

    /**
     * @brief Set the day of the week.
     *
     * Set the day of the week in decimal.
     *
     * @param[in]   dayOfTheWeek   The day of the week in decimal.
     */
    void setDayOfTheWeek(uint8_t dayOfTheWeek);

    /**
     * @brief Set the day of the month.
     *
     * Set the day of the month in decimal.
     *
     * @param[in]   dayOfTheMonth   The day of the month in decimal.
     */
    void setDayOfTheMonth(uint8_t dayOfTheMonth);

    /**
     * @brief Set the month number.
     *
     * Set the month in decimal.
     *
     * @param[in]   month   The month in decimal.
     */
    void setMonth(uint8_t month);

    /**
     * @brief Set the year number.
     *
     * Set the year in decimal.
     *
     * @param[in]   year   The year in decimal.
     */
    void setYear(uint8_t year);

    /**
     * @brief Set the total amount of seconds.
     *
     * Set the time using the total amount of seconds.
     *
     * @param[in]   totalSeconds   Total amount of seconds.
     */
    void setTotalSeconds(uint64_t totalSeconds);
    /**
     * @brief Set the time.
     *
     * Set the values seconds, minutes and hours.
     *
     * @param[in]   seconds   The amount of seconds in decimal.
     * @param[in]   minutes   The amount of minutes in decimal.
     * @param[in]   hours     The amount of hours in decimal.
     */
    void setTime(uint8_t seconds, uint8_t minutes, uint8_t hours);

    /**
     * @brief Set the date.
     *
     * Set the values dayOfTheMonth, month and year.
     *
     * @param[in]   dayOfTheMonth   The day of the month in decimal.
     * @param[in]   month           The month in decimal.
     * @param[in]   year            The year in decimal.
     */
    void setDate(uint8_t dayOfTheMonth, uint8_t month, uint8_t year);

    /**
     * @brief Set all the values.
     *
     * Set the values seconds, minutes, hours, dayOfTheWeek, dayOfTheMonth,
     * month and year.
     *
     * @param[in]   seconds   The amount of seconds in decimal.
     * @param[in]   minutes   The amount of minutes in decimal.
     * @param[in]   hours     The amount of hours in decimal.
     * @param[in]   dayOfTheWeek The day of the week in decimal.
     * @param[in]   dayOfTheMonth The day of the month in decimal.
     * @param[in]   month     The month in decimal.
     * @param[in]   year      The year in decimal.
     */
    void set(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek, uint8_t dayOfTheMonth, uint8_t month,
             uint8_t year);

    /**
     * @brief Equal operator.
     *
     * Equal operator for comparing two RTCTime structs.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return Boolean of whether or not the lhs is equal to the rhs.
     */
    bool operator==(const RTCTime &rhs) const;

    /**
     * @brief Less than operator.
     *
     * Less than operator for comparing two RTCTime structs.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return Boolean of whether or not the lhs is smaller than the rhs.
     */
    bool operator<(const RTCTime &rhs) const;

    /**
     * @brief More than operator.
     *
     * More than operator for comparing two RTCTime structs.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return Boolean of whether or not the lhs is larger than the rhs.
     */
    bool operator>(const RTCTime &rhs) const;

    /**
     * @brief Less than or equal operator.
     *
     * Less than or equal operator for comparing two RTCTime structs.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return Boolean of whether or not the lhs is smaller or equal than the
     * rhs.
     */
    bool operator<=(const RTCTime &rhs) const;

    /**
     * @brief More than or equal operator.
     *
     * More than or equal operator for comparing two RTCTime structs.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return Boolean of whether or not the lhs is larger or equal than the
     * rhs.
     */
    bool operator>=(const RTCTime &rhs) const;

    /**
     * @brief Subtract operator.
     *
     * Subtract operator for subtracting two RTCTime structs.
     * The result will be in seconds.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return RTCTime The delta between the two structs in a RTCTime struct.
     */
    RTCTime operator-(const RTCTime &rhs) const;

    /**
     * @brief Subtract equals operator.
     *
     * Subtract equals operator for subtracting two RTCTime structs.
     * The lhs will be the result.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return The lhs object where the result is saved in.
     */
    RTCTime &operator-=(const RTCTime &rhs);

    /**
     * @brief Plus operator.
     *
     * Plus operator for adding two RTCTime structs together.
     * The result will be in seconds.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return RTCTime The delta between the two structs in a RTCTime struct.
     */
    RTCTime operator+(const RTCTime &rhs) const;

    /**
     * @brief Plus equals operator.
     *
     * Plus equals operator for adding two RTCTime structs together.
     * The lhs will be the result.
     *
     * @param[in]   rhs    RTCTime struct for the right side of the operator.
     * @return The lhs object where the result is saved in.
     */
    RTCTime &operator+=(const RTCTime &rhs);
};

} // namespace Time

#endif // RTC_TIME_HPP
