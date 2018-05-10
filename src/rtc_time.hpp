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
    RTCTime(){};

    uint8_t getSeconds();
    uint8_t getMinutes();
    uint8_t getHours();
    uint8_t getDayOfTheWeek();
    uint8_t getDayOfTheMonth();
    uint8_t getMonth();
    uint8_t getYear();



    void setSeconds(uint8_t seconds);
    void setMinutes(uint8_t minutes);
    void setHours(uint8_t hours);
    void setDayOfTheWeek(uint8_t dayOfTheWeek);
    void setDayOfTheMonth(uint8_t dayOfTheMonth);
    void setMonth(uint8_t month);
    void setYear(uint8_t year);

    void setTime(uint8_t seconds, uint8_t minutes, uint8_t hours);
    void setDate(uint8_t dayOfTheMonth, uint8_t month, uint8_t year);
    void set(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek,
            uint8_t dayOfTheMonth, uint8_t month, uint8_t year);

};

#endif // RTC_TIME_H
