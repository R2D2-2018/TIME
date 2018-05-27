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

TEST_CASE("RTCTime to seconds") {
    SECTION("Test seconds") {
        Time::RTCTime temp(30, 0, 0, 0, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 30);
    }

    SECTION("Test minutes") {
        Time::RTCTime temp(0, 7, 0, 0, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 420);
    }

    SECTION("Test hours") {
        Time::RTCTime temp(0, 0, 12, 0, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 43200);
    }

    SECTION("Test days") {
        Time::RTCTime temp(0, 0, 0, 0, 5, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 432000);
    }

    SECTION("Test months") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 10, 0);

        REQUIRE(temp.getTotalSeconds() == 23587200);
    }

    SECTION("Test years") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 1, 12);

        REQUIRE(temp.getTotalSeconds() == 378691200);
    }
}

TEST_CASE("RTCTime math") {
    Time::RTCTime temp(0, 0, 0, 0, 1, 1, 0);
    Time::RTCTime temp2(30, 0, 0, 0, 1, 1, 0);
    Time::RTCTime temp3(24, 56, 13, 0, 6, 2, 1);

    SECTION("Subtraction") {
        REQUIRE(temp - temp2 == -30);
        REQUIRE(temp - temp3 == 34869384);
    }
}
