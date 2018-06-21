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

void mainMenu(Time::TimeManager &clock, TimeManagerStates *timeMngrState) {
    char someInput;
    hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
    hwlib::cout << "Press 1 to cycle through menu, press 2 to select menu, press 3 to set system time" << hwlib::endl;

    // if (clock.getTime() - now >= 60) {
    //     hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
    //     now = clock.getTime();
    // }

    hwlib::cin >> someInput;

    if (someInput == '1') {
        *timeMngrState = TimeManagerStates::TIMER_SELECT;
    }
    if (someInput == '3') {
        *timeMngrState = TimeManagerStates::SET_TIME;
        hwlib::cout << "Setting the time.." << hwlib::endl;
    }
}

void setTime(Time::TimeManager &clock, TimeManagerStates *timeMngrState) {
    char someInput;
    Time::RTCTime temp(0, 0, 0, 0, 0, 1, 2016);
    hwlib::cout << "Press 1 to increase the year, press 2 to decrease the year, press 4 to confirm and press 3 to cancel"
                << hwlib::endl;
    hwlib::cout << temp.getYear() << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == 1) {
        temp.setYear(temp.getYear() + 1);
        hwlib::cout << temp.getYear() << hwlib::endl;
    }
    if (someInput == 2) {
        temp.setYear(temp.getYear() - 1);
        hwlib::cout << temp.getYear() << hwlib::endl;
    }
    if (someInput == 3) {
        *timeMngrState = TimeManagerStates::MAIN_MENU;
    }
    if (someInput == 4) {
        hwlib::cout << "Year set. Set month:" << hwlib::endl;
        hwlib::cout << "Press 1 to cycle through months, press 2 to confirm and press 3 to cancel" << hwlib::endl;
        hwlib::cout << temp.getMonth() << hwlib::endl;
        hwlib::cin >> someInput;
        if (someInput == 1) {
            temp.setMonth(temp.getMonth() + 1);
            hwlib::cout << temp.getMonth() << hwlib::endl;
        }
        if (someInput == 2) {
            hwlib::cout << "Month set, set date:" << hwlib::endl;
            hwlib::cout << "Press 1 to cycle through days, press 2 to confirm and press 3 to cancel" << hwlib::endl;
            hwlib::cout << temp.getDayOfTheMonth() << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == 1) {
                temp.setDayOfTheMonth(temp.getDayOfTheMonth() + 1);
                hwlib::cout << temp.getDayOfTheMonth() << hwlib::endl;
            }
            if (someInput == 2) {
                hwlib::cout << "Day set, set current hour:" << hwlib::endl;
                hwlib::cout << "Press 1 to cycle through hours, press 2 to confirm and press 3 to cancel" << hwlib::endl;
                hwlib::cout << temp.getHours() << hwlib::endl;
                hwlib::cin >> someInput;
                if (someInput == 1) {
                    temp.setHours(temp.getHours() + 1);
                    hwlib::cout << temp.getHours() << hwlib::endl;
                }
                if (someInput == 2) {
                    hwlib::cout << "Hours set, set minutes:" << hwlib::endl;
                    hwlib::cout << "Press 1 to cycle through minutes, press 2 to confirm and press 3 to cancel" << hwlib::endl;
                    hwlib::cout << temp.getMinutes() << hwlib::endl;
                    hwlib::cin >> someInput;
                    if (someInput == 1) {
                        temp.setMinutes(temp.getMinutes() + 1);
                        hwlib::cout << temp.getMinutes() << hwlib::endl;
                    }
                    if (someInput == 2) {
                        hwlib::cout << "Time setting is finished with this time:\n " << temp.getHours() << ':' << temp.getMinutes()
                                    << '\t' << temp.getDayOfTheMonth() << '/' << temp.getMonth() << '/' << temp.getYear()
                                    << hwlib::endl;
                        hwlib::cout << "Returning to main menu" << hwlib::endl;
                    }
                    if (someInput == 3) {
                        *timeMngrState = TimeManagerStates::MAIN_MENU;
                        return;
                    }
                }
                if (someInput == 3) {
                    *timeMngrState = TimeManagerStates::MAIN_MENU;
                    return;
                }
            }
            if (someInput == 3) {
                *timeMngrState = TimeManagerStates::MAIN_MENU;
                return;
            }
        }
        if (someInput == 3) {
            *timeMngrState = TimeManagerStates::MAIN_MENU;
            return;
        }
    }
    *timeMngrState = TimeManagerStates::MAIN_MENU;
    clock.setTime(temp);
}

void timerSelect(Time::TimeManager &clock, TimeManagerStates *timeMngrState) {
    char someInput;
    hwlib::cout << "Timer menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        *timeMngrState = TimeManagerStates::ALARM_SELECT;
    }
    if (someInput == '2') {
        *timeMngrState = TimeManagerStates::TIMER;
    }
    if (someInput == '3') {
        *timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void alarmSelect(Time::TimeManager &clock, TimeManagerStates *timeMngrState) {
    char someInput;
    hwlib::cout << "Alarm menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        *timeMngrState = TimeManagerStates::TIMER_SELECT;
    }
    if (someInput == '2') {
        *timeMngrState = TimeManagerStates::ALARM;
    }
    if (someInput == '3') {
        *timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void timerMenu(Time::TimeManager &clock, TimeManagerStates *timeMngrState, uint16_t &timerCounter) {
    char someInput;
    hwlib::cout << "Timer selected.Press 1 to cycle through timers, press 2 to start a timer \n Press 4 to reset a timer, "
                   "press 5 to clear a timer \n Press 3 to return to main menu"
                << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timerCounter++;
    }
    if (someInput == '2') {
        clock.setTimer(timerCounter);
    }
    if (someInput == '3') {
        *timeMngrState = TimeManagerStates::MAIN_MENU;
    }
    if (someInput == '4') {
        clock.resetTimer(timerCounter);
    }
    if (someInput == '5') {
        clock.clearTimer(timerCounter);
    }
}

void alarmMenu(Time::TimeManager &clock, TimeManagerStates *timeMngrState, uint16_t &alarmCounter) {
    char someInput;
    hwlib::cout << "Alarm selected.Press 1 to cycle through alarms, press 2 to start an alarms \n Press 4 to clear an alarms, "
                   "\n Press 3 to return to main menu"
                << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        alarmCounter++;
    }
    if (someInput == '2') {
        *timeMngrState = TimeManagerStates::SET_ALARM;
    }
    if (someInput == '3') {
        *timeMngrState = TimeManagerStates::MAIN_MENU;
    }
    if (someInput == '4') {
        clock.clearAlarm(alarmCounter);
    }
}

#endif // STATE_MACHINE_HPP
