/**
 * @file
 * @brief     CPP file for the RTCTime struct.
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#include "rtc_time.hpp"

namespace Time {
RTCTime::RTCTime(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek, uint8_t dayOfTheMonth, uint8_t month,
                 uint8_t year)
    : seconds(seconds), minutes(minutes), hours(hours), dayOfTheWeek(dayOfTheWeek), dayOfTheMonth(dayOfTheMonth), month(month),
      year(year) {
}

RTCTime::RTCTime(uint64_t totalSeconds) {
    if (totalSeconds > 3155759999) {
        totalSeconds = 3155759999;
    }
    setTotalSeconds(totalSeconds);
}

uint8_t RTCTime::getSeconds() const {
    return seconds;
}

uint8_t RTCTime::getMinutes() const {
    return minutes;
}

uint8_t RTCTime::getHours() const {
    return hours;
}

uint8_t RTCTime::getDayOfTheWeek() const {
    return dayOfTheWeek;
}

uint8_t RTCTime::getDayOfTheMonth() const {
    return dayOfTheMonth;
}

uint8_t RTCTime::getMonth() const {
    return month;
}

uint8_t RTCTime::getYear() const {
    return year;
}

uint64_t RTCTime::getTotalSeconds() const {
    uint64_t totalDays = (year % 4 == 0 && month > 2 ? 1 : 0);
    std::array<int, 12> daysTillMonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    totalDays += daysTillMonth[month - 1]; // <- Total days in current year without the days in the current month.
    totalDays += (dayOfTheMonth - 1);      // <- Add the days in the current month.
    totalDays += (year * 365);             // <- Days in a standard year.
    totalDays += ((year + 3) / 4);         // <- Add 1 day for each leap year.
    return seconds + (minutes * 60) + (hours * 3600) + (totalDays * 86400);
}

void RTCTime::setSeconds(uint8_t newSeconds) {
    seconds = newSeconds % 60;
}

void RTCTime::setMinutes(uint8_t newMinutes) {
    minutes = newMinutes % 60;
}

void RTCTime::setHours(uint8_t newHours) {
    hours = newHours % 24;
}

void RTCTime::setDayOfTheWeek(uint8_t newDayOfTheWeek) {
    dayOfTheWeek = newDayOfTheWeek % 7;
    if (dayOfTheWeek == 0) {
        dayOfTheWeek = 7; // The RTCModule does not accept 0.
    }
}

void RTCTime::setDayOfTheMonth(uint8_t newDayOfTheMonth) {
    dayOfTheMonth = newDayOfTheMonth % 31;
    if (dayOfTheMonth == 0) {
        dayOfTheMonth = 31; // The RTCModule does not accept 0.
    }
}

void RTCTime::setMonth(uint8_t newMonth) {
    month = newMonth % 12;
    if (month == 0) {
        month = 12; // The RTCModule does not accept 0.
    }
}

void RTCTime::setYear(uint8_t newYear) {
    year = newYear % 100;
}

void RTCTime::setTotalSeconds(uint64_t totalSeconds) {
    if (totalSeconds > 3155759999) {
        totalSeconds = 3155759999;
    }
    int newYear = 0;
    while (totalSeconds >= 31536000) {                      // <- Total seconds of non-leap year.
        if (newYear % 4 == 0 && totalSeconds >= 31622400) { // <- Check if leap year.
            newYear++;
            totalSeconds -= 31622400;
        } else if (newYear % 4 != 0 && totalSeconds >= 31536000) { // Check if non-leap year
            newYear++;
            totalSeconds -= 31536000;

        } else {
            break;
        }
    }
    setYear(newYear);
    int newMonth = 0;
    std::array<int, 12> daysInMonth = {31, (newYear % 4 == 0 ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (totalSeconds >= static_cast<unsigned int>(daysInMonth[newMonth] * 86400)) {
        totalSeconds -= static_cast<unsigned int>(daysInMonth[newMonth] * 86400);
        newMonth++;
    }

    setMonth(newMonth + 1);
    setDayOfTheMonth((totalSeconds / 86400) + 1);
    totalSeconds %= 86400;
    setHours(totalSeconds / 3600);
    totalSeconds %= 3600;
    setMinutes(totalSeconds / 60);
    totalSeconds %= 60;
    setSeconds(totalSeconds);
}

void RTCTime::setTime(uint8_t newSeconds, uint8_t newMinutes, uint8_t newHours) {
    setSeconds(newSeconds);
    setMinutes(newMinutes);
    setHours(newHours);
}

void RTCTime::setDate(uint8_t newDayOfTheMonth, uint8_t newMonth, uint8_t newYear) {
    setDayOfTheMonth(newDayOfTheMonth);
    setMonth(newMonth);
    setYear(newYear);
}

void RTCTime::set(uint8_t newSeconds, uint8_t newMinutes, uint8_t newHours, uint8_t newDayOfTheWeek, uint8_t newDayOfTheMonth,
                  uint8_t newMonth, uint8_t newYear) {
    setSeconds(newSeconds);
    setMinutes(newMinutes);
    setHours(newHours);
    setDayOfTheWeek(newDayOfTheWeek);
    setDayOfTheMonth(newDayOfTheMonth);
    setMonth(newMonth);
    setYear(newYear);
}

bool RTCTime::operator==(const RTCTime &rhs) const {
    return std::tie(year, month, dayOfTheMonth, hours, minutes, seconds) ==
           std::tie(rhs.year, rhs.month, rhs.dayOfTheMonth, rhs.hours, rhs.minutes, rhs.seconds);
}

bool RTCTime::operator<(const RTCTime &rhs) const {
    return std::tie(year, month, dayOfTheMonth, hours, minutes, seconds) <
           std::tie(rhs.year, rhs.month, rhs.dayOfTheMonth, rhs.hours, rhs.minutes, rhs.seconds);
}

bool RTCTime::operator>(const RTCTime &rhs) const {
    return std::tie(year, month, dayOfTheMonth, hours, minutes, seconds) >
           std::tie(rhs.year, rhs.month, rhs.dayOfTheMonth, rhs.hours, rhs.minutes, rhs.seconds);
}

bool RTCTime::operator<=(const RTCTime &rhs) const {
    return std::tie(year, month, dayOfTheMonth, hours, minutes, seconds) <=
           std::tie(rhs.year, rhs.month, rhs.dayOfTheMonth, rhs.hours, rhs.minutes, rhs.seconds);
}

bool RTCTime::operator>=(const RTCTime &rhs) const {
    return std::tie(year, month, dayOfTheMonth, hours, minutes, seconds) >=
           std::tie(rhs.year, rhs.month, rhs.dayOfTheMonth, rhs.hours, rhs.minutes, rhs.seconds);
}

RTCTime RTCTime::operator-(const RTCTime &rhs) const {
    return RTCTime(getTotalSeconds() - rhs.getTotalSeconds());
}

RTCTime &RTCTime::operator-=(const RTCTime &rhs) {
    *this = *this - rhs;
    return *this;
}

RTCTime RTCTime::operator+(const RTCTime &rhs) const {
    return RTCTime(getTotalSeconds() + rhs.getTotalSeconds());
}

RTCTime &RTCTime::operator+=(const RTCTime &rhs) {
    *this = *this + rhs;
    return *this;
}
} // namespace Time
