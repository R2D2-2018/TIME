#ifndef ENUMSTATES_HPP
#define ENUMSTATES_HPP

enum class timeManagerStates {
    MAIN_MENU,    // Main Menu
    TIMER_SELECT, // Main menu select Timer
    ALARM_SELECT, // Main menu select Alarm
    TIMER,        // Timer menu state
    ALARM,        // Alarm menu state
    SET_ALARM     // Setting an alarm
};

#endif // ENUMSTATES_HPP
