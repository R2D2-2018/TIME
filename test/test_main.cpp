#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "src/rtc_time.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_Case( "Comparison of different RTCTime structs" ) {
    RTCTime time1;
    RTCTime time2;
    time1.set(10, 25, 21, 5, 21, 1, 19);
    time2.set(11, 26, 22, 6, 22, 2, 20);

    REQUIRE((time1 > time2) == false);
    REQUIRE((time1 < time2) == true);
    REQUIRE((time1 >= time1) == true);
    REQUIRE((time2 <= time2) == true);
}
