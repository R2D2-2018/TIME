/**
 * @file
 * @brief     HPP file for the RTCTime struct.
 * @author    Jasper Smienk
 * @license   MIT License
 */

#ifndef RTC_TIME_H
#define RTC_TIME_H

#include <vector>
#include <cstdint>

struct RTCTime {
private:
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t dayOfTheWeek;
    uint8_t dayOfTheMonth;
    uint8_t month;
    uint8_t year;

public:
    /**
     * @brief Default constructor of RTCTime
     */
    RTCTime(){};

    /**
     * @brief Get the amount of seconds.
     * 
     * Get the amount of seconds in decimal.
     * 
     * @return The amount of seconds in decimal.
     */
    uint8_t getSeconds();
    
    /**
     * @brief Get the amount of minutes.
     * 
     * Get the amount of minutes in decimal.
     * 
     * @return The amount of minutes in decimal.
     */
    uint8_t getMinutes();
    
    /**
     * @brief Get the amount of hours.
     * 
     * Get the amount of hours in decimal.
     * 
     * @return The amount of hours in decimal.
     */
    uint8_t getHours();
    
    /**
     * @brief Get the day of the week.
     * 
     * Get the day of the week in decimal.
     * 
     * @return The the day of the week in decimal.
     */
    uint8_t getDayOfTheWeek();
    
    /**
     * @brief Get the day of the month.
     * 
     * Get the day of the month in decimal.
     * 
     * @return The day of the month in decimal.
     */
    uint8_t getDayOfTheMonth();
    
    /**
     * @brief Get the month number.
     * 
     * Get the month in decimal.
     * 
     * @return The month in decimal.
     */
    uint8_t getMonth();
    
    /**
     * @brief Get the year number.
     * 
     * Get the year in decimal.
     * 
     * @return The year in decimal.
     */
    uint8_t getYear();

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
     * Set the values seconds, minutes, hours, dayOfTheWeek, dayOfTheMonth, month and year.
     * 
     * @param[in]   seconds   The amount of seconds in decimal.
     * @param[in]   minutes   The amount of minutes in decimal.
     * @param[in]   hours     The amount of hours in decimal.
     * @param[in]   dayOfTheWeek The day of the week in decimal.
     * @param[in]   dayOfTheMonth The day of the month in decimal.
     * @param[in]   month     The month in decimal.
     * @param[in]   year      The year in decimal.
     */
    void set(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek,
            uint8_t dayOfTheMonth, uint8_t month, uint8_t year);

};

#endif // RTC_TIME_H
