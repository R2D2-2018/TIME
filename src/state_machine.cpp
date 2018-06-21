/**
 * @file
 * @brief     CPP file for the StateMachine class that controls the behaviour of the RTC
 * module
 * @author    Nick Goris
 * @license   MIT License
 */

#include "state_machine.hpp"

StateMachine::StateMachine(Time::TimeManager &clock) : clock(clock) {
}

TimeManagerStates StateMachine::getState() {
    return timeMngrState;
}

void StateMachine::mainMenu() {
    hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
    hwlib::cout << "Press 1 to cycle through menu, press 2 to select menu, press 3 to set system time" << hwlib::endl;

    // if (clock.getTime() - now >= 60) {
    //     hwlib::cout << clock.getTime().getTotalSeconds() << hwlib::endl;
    //     now = clock.getTime();
    // }

    hwlib::cin >> someInput;

    if (someInput == '1') {
        timeMngrState = TimeManagerStates::TIMER_SELECT;
    }
    if (someInput == '3') {
        timeMngrState = TimeManagerStates::SET_TIME;
        hwlib::cout << "Setting the time.." << hwlib::endl;
    }
}

void StateMachine::setTime() {
    bool finished = false;
    Time::RTCTime temp(0, 0, 0, 0, 0, 1, 18);
    hwlib::cout << "Press 1 to increase the year, press 2 to decrease the year, press 4 to confirm and press 3 to cancel"
                << hwlib::endl;
    hwlib::cout << temp.getYear() << hwlib::endl;
    hwlib::cin >> someInput;

    while (!finished) {
        if (someInput == '1') {
            temp.setYear(temp.getYear() + 1);
            hwlib::cout << temp.getYear() << hwlib::endl;
            hwlib::cin >> someInput;
        }
        if (someInput == '2') {
            temp.setYear(temp.getYear() - 1);
            hwlib::cout << temp.getYear() << hwlib::endl;
            hwlib::cin >> someInput;
        }
        if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
            return;
        }
        if (someInput == '4') {
            hwlib::cout << "Year set. Set month:" << hwlib::endl;
            hwlib::cout << "Press 1 to cycle through months, press 2 to confirm and press 3 to cancel" << hwlib::endl;
            hwlib::cout << temp.getMonth() << hwlib::endl;
            hwlib::cin >> someInput;
            if (someInput == '1') {
                temp.setMonth(temp.getMonth() + 1);
                hwlib::cout << temp.getMonth() << hwlib::endl;
            }
            if (someInput == '2') {
                hwlib::cout << "Month set, set date:" << hwlib::endl;
                hwlib::cout << "Press 1 to cycle through days, press 2 to confirm and press 3 to cancel" << hwlib::endl;
                hwlib::cout << temp.getDayOfTheMonth() << hwlib::endl;
                hwlib::cin >> someInput;
                if (someInput == '1') {
                    temp.setDayOfTheMonth(temp.getDayOfTheMonth() + 1);
                    hwlib::cout << temp.getDayOfTheMonth() << hwlib::endl;
                }
                if (someInput == '2') {
                    hwlib::cout << "Day set, set current hour:" << hwlib::endl;
                    hwlib::cout << "Press 1 to cycle through hours, press 2 to confirm and press 3 to cancel" << hwlib::endl;
                    hwlib::cout << temp.getHours() << hwlib::endl;
                    hwlib::cin >> someInput;
                    if (someInput == '1') {
                        temp.setHours(temp.getHours() + 1);
                        hwlib::cout << temp.getHours() << hwlib::endl;
                    }
                    if (someInput == '2') {
                        hwlib::cout << "Hours set, set minutes:" << hwlib::endl;
                        hwlib::cout << "Press 1 to cycle through minutes, press 2 to confirm and press 3 to cancel" << hwlib::endl;
                        hwlib::cout << temp.getMinutes() << hwlib::endl;
                        hwlib::cin >> someInput;
                        if (someInput == '1') {
                            temp.setMinutes(temp.getMinutes() + 1);
                            hwlib::cout << temp.getMinutes() << hwlib::endl;
                        }
                        if (someInput == '2') {
                            hwlib::cout << "Time setting is finished with this time:\n " << temp.getHours() << ':'
                                        << temp.getMinutes() << '\t' << temp.getDayOfTheMonth() << '/' << temp.getMonth() << '/'
                                        << temp.getYear() << hwlib::endl;
                            hwlib::cout << "Returning to main menu" << hwlib::endl;
                            finished = true;
                        }
                        if (someInput == '3') {
                            timeMngrState = TimeManagerStates::MAIN_MENU;
                            return;
                        }
                    }
                    if (someInput == '3') {
                        timeMngrState = TimeManagerStates::MAIN_MENU;
                        return;
                    }
                }
                if (someInput == '3') {
                    timeMngrState = TimeManagerStates::MAIN_MENU;
                    return;
                }
            }
            if (someInput == '3') {
                timeMngrState = TimeManagerStates::MAIN_MENU;
                return;
            }
        }
    }
    timeMngrState = TimeManagerStates::MAIN_MENU;
    clock.setTime(temp);
}

void StateMachine::timerSelect() {
    hwlib::cout << "Timer menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timeMngrState = TimeManagerStates::ALARM_SELECT;
    }
    if (someInput == '2') {
        timeMngrState = TimeManagerStates::TIMER;
    }
    if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void StateMachine::alarmSelect() {
    hwlib::cout << "Alarm menu? Press 2 to confirm, press 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timeMngrState = TimeManagerStates::TIMER_SELECT;
    }
    if (someInput == '2') {
        timeMngrState = TimeManagerStates::ALARM;
    }
    if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void StateMachine::timerMenu(uint16_t &timerCounter) {
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
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
    if (someInput == '4') {
        clock.resetTimer(timerCounter);
    }
    if (someInput == '5') {
        clock.clearTimer(timerCounter);
    }
}

void StateMachine::alarmMenu(uint16_t &alarmCounter) {
    hwlib::cout << "Alarm selected.Press 1 to cycle through alarms, press 2 to start an alarms \n Press 4 to clear an alarms, "
                   "\n Press 3 to return to main menu"
                << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        alarmCounter++;
    }
    if (someInput == '2') {
        timeMngrState = TimeManagerStates::SET_ALARM;
    }
    if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
    if (someInput == '4') {
        clock.clearAlarm(alarmCounter);
    }
}