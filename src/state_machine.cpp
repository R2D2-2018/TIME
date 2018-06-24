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
    hwlib::cout << static_cast<int>(clock.getTime().getHours()) << ':' << static_cast<int>(clock.getTime().getMinutes()) << '\t'
                << static_cast<int>(clock.getTime().getDayOfTheMonth()) << '/' << static_cast<int>(clock.getTime().getMonth())
                << '/' << static_cast<int>(clock.getTime().getYear()) << hwlib::endl;
    hwlib::cout << "Press 1 to cycle through menu, press 2 to select menu,\npress 3 to set system time" << hwlib::endl;

    hwlib::cin >> someInput;

    if (someInput == '1') {
        timeMngrState = TimeManagerStates::TIMER_SELECT;
    } else if (someInput == '3') {
        previousState = TimeManagerStates::MAIN_MENU;
        timeMngrState = TimeManagerStates::SET_TIME;
        hwlib::cout << "Setting the time.." << hwlib::endl;
    } else {
        hwlib::cout << static_cast<int>(clock.getTime().getHours()) << ':' << static_cast<int>(clock.getTime().getMinutes()) << '\t'
                    << static_cast<int>(clock.getTime().getDayOfTheMonth()) << '/' << static_cast<int>(clock.getTime().getMonth())
                    << '/' << static_cast<int>(clock.getTime().getYear()) << hwlib::endl;

        for (int16_t i = 0; i < clock.getTimerArraySize(); ++i) {
            if (clock.checkActiveTimer(i)) {
                hwlib::cout << "Timer " << i + 1 << "is currently at: " << static_cast<int>(clock.elapsedTime(i).getTotalSeconds())
                            << hwlib::endl;
            }
        }
    }
}

void StateMachine::setYear() {

    hwlib::cout << "Press 1 to increase the year, press 2 to decrease the year,\npress 4 to confirm and press 3 to cancel"
                << hwlib::endl;
    hwlib::cout << static_cast<int>(temp.getYear()) << hwlib::endl;

    while (timeMngrState != TimeManagerStates::MAIN_MENU) {
        hwlib::cin >> someInput;

        if (someInput == '1') {
            temp.setYear(temp.getYear() + 1);
            hwlib::cout << static_cast<int>(temp.getYear()) << hwlib::endl;
            hwlib::cin >> someInput;
        } else if (someInput == '2') {
            temp.setYear(temp.getYear() - 1);
            hwlib::cout << static_cast<int>(temp.getYear()) << hwlib::endl;
            hwlib::cin >> someInput;
        } else if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
            return;
        } else if (someInput == '4') {
            hwlib::cout << "Year set. Set month:" << hwlib::endl;
            StateMachine::setMonth();
        }
    }
}

void StateMachine::setMonth() {
    hwlib::cout << "Press 1 to cycle through months, press 2 to confirm\nand press 3 to cancel" << hwlib::endl;
    hwlib::cout << static_cast<int>(temp.getMonth()) << hwlib::endl;
    while (timeMngrState != TimeManagerStates::MAIN_MENU) {
        hwlib::cin >> someInput;

        if (someInput == '1') {
            temp.setMonth(temp.getMonth() + 1);
            hwlib::cout << static_cast<int>(temp.getMonth()) << hwlib::endl;
        } else if (someInput == '2') {
            hwlib::cout << "Month set, set date:" << hwlib::endl;
            StateMachine::setDayOfMonth();
        } else if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
        }
    }
}

void StateMachine::setDayOfMonth() {
    hwlib::cout << "Press 1 to cycle through days, press 2 to confirm\nand press 3 to cancel" << hwlib::endl;
    hwlib::cout << static_cast<int>(temp.getDayOfTheMonth()) << hwlib::endl;

    while (timeMngrState != TimeManagerStates::MAIN_MENU) {
        hwlib::cin >> someInput;
        if (someInput == '1') {
            temp.setDayOfTheMonth(temp.getDayOfTheMonth() + 1);
            hwlib::cout << static_cast<int>(temp.getDayOfTheMonth()) << hwlib::endl;
        } else if (someInput == '2') {
            hwlib::cout << "Day set, set hour:" << hwlib::endl;
            StateMachine::setHour();
        } else if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
        }
    }
}

void StateMachine::setHour() {
    hwlib::cout << "Press 1 to cycle through hours, press 2 to confirm and press 3 to cancel" << hwlib::endl;
    hwlib::cout << static_cast<int>(temp.getHours()) << hwlib::endl;
    while (timeMngrState != TimeManagerStates::MAIN_MENU) {
        hwlib::cin >> someInput;
        if (someInput == '1') {
            temp.setHours(temp.getHours() + 1);
            hwlib::cout << static_cast<int>(temp.getHours()) << hwlib::endl;
        } else if (someInput == '2') {
            hwlib::cout << "Hours set, set minutes:" << hwlib::endl;
            StateMachine::setMinutes();
        } else if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
        }
    }
}

void StateMachine::setMinutes() {
    hwlib::cout << "Press 1 to cycle through minutes, press 2 to confirm\nand press 3 to cancel" << hwlib::endl;
    hwlib::cout << static_cast<int>(temp.getMinutes()) << hwlib::endl;
    while (timeMngrState != TimeManagerStates::MAIN_MENU) {
        hwlib::cin >> someInput;
        if (someInput == '1') {
            temp.setMinutes(temp.getMinutes() + 1);
            hwlib::cout << static_cast<int>(temp.getMinutes()) << hwlib::endl;
        } else if (someInput == '2') {
            hwlib::cout << "Time setting is finished with this time:\n " << static_cast<int>(clock.getTime().getHours()) << ':'
                        << static_cast<int>(clock.getTime().getMinutes()) << '\t'
                        << static_cast<int>(clock.getTime().getDayOfTheMonth()) << '/'
                        << static_cast<int>(clock.getTime().getMonth()) << '/' << static_cast<int>(clock.getTime().getYear())
                        << hwlib::endl;
            hwlib::cout << "Returning to main menu" << hwlib::endl;
            timeMngrState = TimeManagerStates::MAIN_MENU;
            if (previousState == TimeManagerStates::MAIN_MENU) {
                clock.setTime(temp);
            } else if (previousState == TimeManagerStates::ALARM_SELECT) {
                clock.setAlarm(alarmCounter, temp);
            }
        } else if (someInput == '3') {
            timeMngrState = TimeManagerStates::MAIN_MENU;
        }
    }
}

void StateMachine::setTime() {
    setYear();
}

void StateMachine::timerSelect() {
    hwlib::cout << "Timer menu? Press 2 to confirm,\npress 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timeMngrState = TimeManagerStates::ALARM_SELECT;
    } else if (someInput == '2') {
        timeMngrState = TimeManagerStates::TIMER;
    } else if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void StateMachine::alarmSelect() {
    hwlib::cout << "Alarm menu? Press 2 to confirm,\npress 3 to cancel" << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timeMngrState = TimeManagerStates::TIMER_SELECT;
    } else if (someInput == '2') {
        previousState = TimeManagerStates::ALARM_SELECT;
        timeMngrState = TimeManagerStates::ALARM;
    } else if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    }
}

void StateMachine::timerMenu() {
    hwlib::cout << "Timer selected.Press 1 to cycle through timers, press 2 to start a timer \n Press 4 to reset a timer, "
                   "press 5 to clear a timer\nPress 3 to return to main menu"
                << hwlib::endl;
    hwlib::cout << "Set timer " << timerCounter + 1 << '?' << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        timerCounter++;
        timerCounter = timerCounter % clock.getTimerArraySize();
    } else if (someInput == '2') {
        clock.setTimer(timerCounter);
    } else if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    } else if (someInput == '4') {
        clock.resetTimer(timerCounter);
    } else if (someInput == '5') {
        clock.clearTimer(timerCounter);
    }
}

void StateMachine::alarmMenu() {
    hwlib::cout << "Alarm selected.Press 1 to cycle through alarms, press 2 to start an alarms \nPress 4 to clear an alarms, "
                   "Press 3 to return to main menu"
                << hwlib::endl;
    hwlib::cout << "Set alarm " << alarmCounter + 1 << '?' << hwlib::endl;
    hwlib::cin >> someInput;
    if (someInput == '1') {
        alarmCounter++;
        alarmCounter = alarmCounter % clock.getAlarmArraySize();
    } else if (someInput == '2') {
        timeMngrState = TimeManagerStates::SET_ALARM;
    } else if (someInput == '3') {
        timeMngrState = TimeManagerStates::MAIN_MENU;
    } else if (someInput == '4') {
        clock.clearAlarm(alarmCounter);
    }
}