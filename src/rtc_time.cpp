/**
 * @file
 * @brief     CPP file for the RTCTime struct.
 * @author    Jasper Smienk
 * @license   MIT License
 */

#include "rtc_time.hpp"

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



void RTCTime::setSeconds(uint8_t newSeconds) {
    seconds = newSeconds;
}

void RTCTime::setMinutes(uint8_t newMinutes) {
    minutes = newMinutes;
}

void RTCTime::setHours(uint8_t newHours) {
    hours = newHours;
}

void RTCTime::setDayOfTheWeek(uint8_t newDayOfTheWeek) {
    dayOfTheWeek = newDayOfTheWeek;
}

void RTCTime::setDayOfTheMonth(uint8_t newDayOfTheMonth) {
    dayOfTheMonth = newDayOfTheMonth;
}

void RTCTime::setMonth(uint8_t newMonth) {
    month = newMonth;
}

void RTCTime::setYear(uint8_t newYear) {
    year = newYear;
}


void RTCTime::setTime(uint8_t newSeconds, uint8_t newMinutes, uint8_t newHours) {
    seconds = newSeconds;
    minutes = newMinutes;
    hours = newHours;
}

void RTCTime::setDate(uint8_t newDayOfTheMonth, uint8_t newMonth, uint8_t newYear) {
    dayOfTheMonth = newDayOfTheMonth;
    month = newMonth;
    year = newYear;
}

void RTCTime::set(uint8_t newSeconds, uint8_t newMinutes, uint8_t newHours, uint8_t newDayOfTheWeek,
            uint8_t newDayOfTheMonth, uint8_t newMonth, uint8_t newYear) {
    seconds = newSeconds;
    minutes = newMinutes;
    hours = newHours;
    dayOfTheWeek = newDayOfTheWeek;
    dayOfTheMonth = newDayOfTheMonth;
    month = newMonth;
    year = newYear;
}
