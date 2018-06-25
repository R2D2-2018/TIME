/**
 * @file
 * @brief     CPP file for the StateMachine class that controls the behaviour of the RTC
 * module
 * @author    Nick Goris
 * @license   MIT License
 */

#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "rtc_time.hpp"
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

namespace Time {
class StateMachine {
  private:
    ///< TimeManagerStates object that keeps track of the current state, initialised at MAIN_MENU
    TimeManagerStates timeMngrState = TimeManagerStates::MAIN_MENU;
    ///< TimeManagerStates object that keeps track of the previous state, initialised at MAIN_MENU
    TimeManagerStates previousState = TimeManagerStates::MAIN_MENU;

    ///< Char variable that stores user input at various points
    char someInput = '\0';

    ///< Reference to TimeManager Object clock, which is the instantiation of the RTC module
    Time::TimeManager &clock;

    ///< Temporary RTCTime object, initialised at 0:0 0/1/18, used to store temporary time profiles during alarm and system time
    ///< settings
    Time::RTCTime temp = {0, 0, 0, 0, 0, 1, 18};

    ///< Counter that keeps track of the selecter timer
    uint16_t timerCounter = 0;

    ///< Counter that keeps track of the selected alarm
    uint16_t alarmCounter = 0;

  public:
    /**
     * @brief Default constructor
     *
     * Default constructor for the TimeManager StateMachine class
     *
     * @param[in]   clock     The TimeManager object this State Machine manages the states for
     */
    explicit StateMachine(Time::TimeManager &clock);

    /**
     * @brief Returns current state
     *
     * Get function to return the current state of the STM
     */
    TimeManagerStates getState();

    /**
     * @brief Main menu function
     *
     * This function is called in the Main Menu state. This is the default state at the beginning and when cancelling from any other
     * state.
     */
    void mainMenu();

    /**
     * @brief Sets time of internal temp RTCTime object
     *
     * This function is called to set the internal RTCTime temporary object. This is used a as a buffer to then write to external
     * RTCTime objects, such as the system time or an alarm
     */
    void setTime();

    /**
     * @brief Timer select function
     *
     * This function is called from the Main Menu state, when the submenu for setting a Timer is selected
     */
    void timerSelect();

    /**
     * @brief Alarm select function
     *
     * This function is called from the Main Menu state, when the submenu for setting a Alarm is selected
     */
    void alarmSelect();

    /**
     * @brief Timer Menu function
     *
     * This function is called from the timer select state, when the timer submenu choice is confirmed
     */
    void timerMenu();

    /**
     * @brief Alarm Menu function
     *
     * This function is called from the alarm select state, when the alarm submenu choice is confirmed
     */
    void alarmMenu();

    /**
     * @brief Set year function
     *
     * This function is called from the set time state, it sets the year of the internal RTCTime temporary object
     */
    void setYear();

    /**
     * @brief Set month function
     *
     * This function is called from the set time state, it sets the month of the internal RTCTime temporary object
     */
    void setMonth();

    /**
     * @brief Set day of month function
     *
     * This function is called from the set time state, it sets the day of month of the internal RTCTime temporary object
     */
    void setDayOfMonth();

    /**
     * @brief Set hour function
     *
     * This function is called from the set time state, it sets the hour of the internal RTCTime temporary object
     */
    void setHour();

    /**
     * @brief Set minutes function
     *
     * This function is called from the set time state, it sets the minutes of the internal RTCTime temporary object
     */
    void setMinutes();
};
} // namespace Time

#endif // STATE_MACHINE_HPP
