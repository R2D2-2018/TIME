/**
 * @file
 * @brief     CPP file for the TimeManager class to control the DS3231 RTC
 * module
 * @author    Jasper Smienk, Nick Goris
 * @license   MIT License
 */

#include "time_manager.hpp"
#include "rtc_time.hpp"

namespace Time {
TimeManager::TimeManager(hwlib::pin_oc &scl, hwlib::pin_oc &sda)
    : scl(scl), sda(sda), realTimeClock(hwlib::i2c_bus_bit_banged_scl_sda(scl, sda)) {
    TimeManager::setTime(RTCTime(0));
}

RTCTime TimeManager::getTime() {
    uint8_t zero[] = {0};               // Todo: Find better way for this.
    realTimeClock.write(0x68, zero, 1); // Set address register to 0.

    uint8_t data[7];
    realTimeClock.read(0x68, data, 7);

    RTCTime timeAndDate;
    timeAndDate.set(BCDToDec(data[0]), BCDToDec(data[1]), BCDToDec(data[2]), BCDToDec(data[3]), BCDToDec(data[4]),
                    BCDToDec(data[5]), BCDToDec(data[6]));
    return timeAndDate;
}

void TimeManager::setTime(RTCTime timeAndDate) {

    uint8_t data[] = {0,
                      decToBCD(timeAndDate.getSeconds()),
                      decToBCD(timeAndDate.getMinutes()),
                      decToBCD(timeAndDate.getHours()),
                      decToBCD(timeAndDate.getDayOfTheWeek()),
                      decToBCD(timeAndDate.getDayOfTheMonth()),
                      decToBCD(timeAndDate.getMonth()),
                      decToBCD(timeAndDate.getYear())};
    realTimeClock.write(0x68, data, 8);
}

void TimeManager::setAlarm(int alarmId, RTCTime newAlarm) {
    alarmArray[alarmId] = newAlarm;
    activeAlarms[alarmId] = true;
}

void TimeManager::clearAlarm(int alarmId) {
    activeAlarms[alarmId] = false;
}

uint16_t TimeManager::getAlarmArraySize() {
    return ALARM_AMOUNT;
}

bool TimeManager::checkAlarm(int alarmId) {
    if (activeAlarms[alarmId]) {
        if (alarmArray[alarmId] <= getTime()) {
            hwlib::cout << "BEEP BEEP" << hwlib::endl;
            return true;
        }
        return false;
    }
    return false;
}

void TimeManager::setTimer(int timerId) {
    if (!activeTimers[timerId]) {
        timerArray[timerId] = getTime();
        activeTimers[timerId] = true;
    }
}

uint16_t TimeManager::getTimerArraySize() const {
    return timerArray.size();
}

RTCTime TimeManager::elapsedTime(int timerId) {
    if (activeTimers[timerId]) {
        return (getTime() - timerArray[timerId]);
    }
    return RTCTime();
}

void TimeManager::resetTimer(int timerId) {
    if (activeTimers[timerId]) {
        timerArray[timerId] = getTime();
    }
}

void TimeManager::clearTimer(int timerId) {
    resetTimer(timerId);
    stopTimer(timerId);
}

void TimeManager::stopTimer(int timerId) {
    activeTimers[timerId] = false;
}
} // namespace Time
