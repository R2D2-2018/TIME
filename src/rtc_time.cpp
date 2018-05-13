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



void RTCTime::setSeconds(uint8_t seconds) {
    seconds = seconds;
}

void RTCTime::setMinutes(uint8_t minutes) {
    minutes = minutes;
}

void RTCTime::setHours(uint8_t hours) {
    hours = hours;
}

void RTCTime::setDayOfTheWeek(uint8_t dayOfTheWeek) {
    dayOfTheWeek = dayOfTheWeek;
}

void RTCTime::setDayOfTheMonth(uint8_t dayOfTheMonth) {
    dayOfTheMonth = dayOfTheMonth;
}

void RTCTime::setMonth(uint8_t month) {
    month = month;
}

void RTCTime::setYear(uint8_t year) {
    year = year;
}


void RTCTime::setTime(uint8_t seconds, uint8_t minutes, uint8_t hours) {
    seconds = seconds;
    minutes = minutes;
    hours = hours;
}

void RTCTime::setDate(uint8_t dayOfTheMonth, uint8_t month, uint8_t year) {
    dayOfTheMonth = dayOfTheMonth;
    month = month;
    year = year;
}

void RTCTime::set(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek,
            uint8_t dayOfTheMonth, uint8_t month, uint8_t year) {
    seconds = seconds;
    minutes = minutes;
    hours = hours;
    dayOfTheWeek = dayOfTheWeek;
    dayOfTheMonth = dayOfTheMonth;
    month = month;
    year = year;
}
