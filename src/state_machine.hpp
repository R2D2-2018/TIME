/**
 * @file
 * @brief     CPP file for the StateMachine class that controls the behaviour of the RTC
 * module
 * @author    Nick Goris
 * @license   MIT License
 */

#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "time_manager.hpp"

enum class TimeManagerStates {
    MAIN_MENU,    // Main Menu
    SET_TIME,     // Menu to set internal time
    TIMER_SELECT, // Main menu select Timer
    ALARM_SELECT, // Main menu select Alarm
    TIMER,        // Timer menu state
    ALARM,        // Alarm menu state
    SET_ALARM     // Setting an alarm
};

class StateMachine {
  private:
    TimeManagerStates timeMngrState = TimeManagerStates::MAIN_MENU;

    char someInput = '\0';

    Time::TimeManager &clock;

  public:
    StateMachine(Time::TimeManager &clock);

    TimeManagerStates getState();

    void mainMenu();

    void setTime();

    void timerSelect();

    void alarmSelect();

    void timerMenu(uint16_t &timerCounter);

    void alarmMenu(uint16_t &alarmCounter);
};

#endif // STATE_MACHINE_HPP
