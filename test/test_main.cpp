#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rtc_time.hpp"

TEST_CASE("RTCTime comparisons") {
    Time::RTCTime time1(1, 2, 3, 4, 5, 6, 7);
    Time::RTCTime time2(2, 3, 4, 5, 6, 7, 8);

    SECTION("Test less-than operator") {
        REQUIRE((time1 < time2) == true);
    }

    SECTION("Test more-than operator") {
        REQUIRE((time2 > time1) == true);
    }

    SECTION("Test less-than-or-equal operator") {
        REQUIRE((time1 <= time1) == true);
    }

    SECTION("Test more-than-or-equal operator") {
        REQUIRE((time1 >= time1) == true);
    }

    SECTION("Test equal operator") {
        REQUIRE((time1 == time1) == true);
    }
}
