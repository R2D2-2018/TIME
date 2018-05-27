/**
 * @file
 * @brief     CPP file for the RTCTime struct.
 * @author    Jasper Smienk
 * @license   MIT License
 */

#include "rtc_time.hpp"

namespace Time {
RTCTime::RTCTime(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek, uint8_t dayOfTheMonth, uint8_t month,
                 uint8_t year)
    : seconds(seconds), minutes(minutes), hours(hours), dayOfTheWeek(dayOfTheWeek), dayOfTheMonth(dayOfTheMonth), month(month),
      year(year) {
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

unsigned long RTCTime::getTotalSeconds() const {
    unsigned long totalDays = (year % 4 == 0 ? 1 : 0);
    switch (month) { // A switchcase is used because not every month is off equal length.
    case 1:          // Todo: Figure out a formula for this.
        totalDays = 0;
        break;
    case 2:
        totalDays = 31;
        break;
    case 3:
        totalDays += 59;
        break;
    case 4:
        totalDays += 90;
        break;
    case 5:
        totalDays += 120;
        break;
    case 6:
        totalDays += 151;
        break;
    case 7:
        totalDays += 181;
        break;
    case 8:
        totalDays += 212;
        break;
    case 9:
        totalDays += 243;
        break;
    case 10:
        totalDays += 273;
        break;
    case 11:
        totalDays += 304;
        break;
    case 12:
        totalDays += 334;
        break;
    }
    totalDays += (dayOfTheMonth - 1);
    totalDays += (year * 365);
    totalDays += (year / 4); // Add 1 day for each leap year.
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

unsigned long long RTCTime::operator-(const RTCTime &rhs) const {
    return (getTotalSeconds() - rhs.getTotalSeconds());
}
/*
std::ostream &operator<<(std::ostream &stream, const RTCTime &rhs) {
    stream << static_cast<int>(rhs.getHours()) << ":" << static_cast<int>(rhs.getMinutes()) << ":"
           << static_cast<int>(rhs.getSeconds()) << " - " << static_cast<int>(rhs.getDayOfTheWeek()) << " "
           << static_cast<int>(rhs.getDayOfTheMonth()) << "/" << static_cast<int>(rhs.getMonth()) << "/"
           << static_cast<int>(rhs.getYear());
    return stream;
}*/

} // namespace Time
