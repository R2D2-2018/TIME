# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/bcd_conversion.cpp
    src/rtc_time.cpp
    src/time_manager.cpp
    src/state_machine.cpp
)
