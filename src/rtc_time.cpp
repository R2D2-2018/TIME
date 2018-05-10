#include "rtc_time.hpp"

uint8_t RTCTime::getSeconds() {
    return seconds;
}

uint8_t RTCTime::getMinutes() {
    return minutes;
}

uint8_t RTCTime::getHours() {
    return hours;
}

uint8_t RTCTime::getDayOfTheWeek() {
    return dayOfTheWeek;
}

uint8_t RTCTime::getDayOfTheMonth() {
    return dayOfTheMonth;
}

uint8_t RTCTime::getMonth() {
    return month;
}

uint8_t RTCTime::getYear() {
    return year;
}



void RTCTime::setSeconds(uint8_t seconds) {
    this->seconds = seconds;
}

void RTCTime::setMinutes(uint8_t minutes) {
    this->minutes = minutes;
}

void RTCTime::setHours(uint8_t hours) {
    this->hours = hours;
}

void RTCTime::setDayOfTheWeek(uint8_t dayOfTheWeek) {
    this->dayOfTheWeek = dayOfTheWeek;
}

void RTCTime::setDayOfTheMonth(uint8_t dayOfTheMonth) {
    this->dayOfTheMonth = dayOfTheMonth;
}

void RTCTime::setMonth(uint8_t month) {
    this->month = month;
}

void RTCTime::setYear(uint8_t year) {
    this->year = year;
}


void RTCTime::setTime(uint8_t seconds, uint8_t minutes, uint8_t hours) {
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

void RTCTime::setDate(uint8_t dayOfTheMonth, uint8_t month, uint8_t year) {
    this->dayOfTheMonth = dayOfTheMonth;
    this->month = month;
    this->year = year;
}

void RTCTime::set(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayOfTheWeek,
            uint8_t dayOfTheMonth, uint8_t month, uint8_t year) {
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->dayOfTheWeek = dayOfTheWeek;
    this->dayOfTheMonth = dayOfTheMonth;
    this->month = month;
    this->year = year;
}
