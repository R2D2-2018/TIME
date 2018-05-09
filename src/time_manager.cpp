#include "time_manager.hpp"

TimeManager::TimeManager(hwlib::target::pin_oc & scl, hwlib::target::pin_oc & sda):
    scl(scl),
    sda(sda),
    realTimeClock(hwlib::i2c_bus_bit_banged_scl_sda(scl, sda))
{
    
}
