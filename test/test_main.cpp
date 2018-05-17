#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/time_manager.hpp"
#include "../src/rtc_time.hpp"
#include "../src/wrap-hwlib.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE("Time is running") {
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);

    auto clock = time::TimeManager(scl, sda);

    auto firstTime = clock.getTime().getSeconds();
    hwlib::wait_ms(2000);
    auto secondTime = clock.getTime().getSeconds();

    REQUIRE(firstTime != secondTime);
}
