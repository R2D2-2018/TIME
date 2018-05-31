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

        REQUIRE(temp.getTotalSeconds() == 345600);
    }

    SECTION("Test months") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 10, 0);

        REQUIRE(temp.getTotalSeconds() == 23673600);
    }

    SECTION("Test years") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 1, 12);

        REQUIRE(temp.getTotalSeconds() == 378691200);
    }
}

TEST_CASE("Seconds to RTCTime") {
    SECTION("Test seconds") {
        Time::RTCTime temp(59, 0, 0, 0, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(59);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test minutes") {
        Time::RTCTime temp(0, 59, 0, 0, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3540);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test hours") {
        Time::RTCTime temp(0, 0, 23, 0, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(82800);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test days") {
        Time::RTCTime temp(0, 0, 0, 0, 31, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(2592000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test months") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 12, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(28944000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test years") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 1, 99);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3124224000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test lower bound") {
        Time::RTCTime temp(0, 0, 0, 0, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(0);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SwECTION("Test upper bound") {
        Time::RTCTime temp(59, 59, 23, 0, 31, 12, 99);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3155846397);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }
}

TEST_CASE("RTCTime math") {
    Time::RTCTime temp(0, 0, 0, 0, 1, 1, 0);
    Time::RTCTime temp2(30, 0, 0, 0, 1, 1, 0);
    Time::RTCTime temp3(0, 30, 0, 0, 1, 1, 0);
    Time::RTCTime temp4(0, 0, 10, 0, 1, 1, 0);
    Time::RTCTime temp5(0, 0, 0, 0, 26, 1, 0);
    Time::RTCTime temp6(0, 0, 0, 0, 1, 5, 0);
    Time::RTCTime temp7(0, 0, 0, 0, 1, 1, 48);
    Time::RTCTime temp8(24, 56, 13, 0, 6, 2, 1);

    SECTION("Subtraction") {
        REQUIRE(temp - temp2 == -30);
        REQUIRE(temp - temp3 == -1800);
        REQUIRE(temp - temp4 == -36000);
        REQUIRE(temp - temp5 == -2160000);
        REQUIRE(temp - temp6 == -10454400);
        REQUIRE(temp - temp7 == -1514764800);
        REQUIRE(temp - temp8 == -34782984);
    }
}
