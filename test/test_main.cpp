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
        Time::RTCTime temp(30, 0, 0, 1, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 30);
    }

    SECTION("Test minutes") {
        Time::RTCTime temp(0, 7, 0, 1, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 420);
    }

    SECTION("Test hours") {
        Time::RTCTime temp(0, 0, 12, 1, 1, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 43200);
    }

    SECTION("Test days") {
        Time::RTCTime temp(0, 0, 0, 1, 5, 1, 0);

        REQUIRE(temp.getTotalSeconds() == 345600);
    }

    SECTION("Test months") {
        Time::RTCTime temp(0, 0, 0, 1, 1, 10, 0);

        REQUIRE(temp.getTotalSeconds() == 23673600);
    }

    SECTION("Test years") {
        Time::RTCTime temp(0, 0, 0, 1, 1, 1, 12);

        REQUIRE(temp.getTotalSeconds() == 378691200);
    }
}

TEST_CASE("Seconds to RTCTime") {
    SECTION("Test seconds") {
        Time::RTCTime temp(59, 0, 0, 1, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(59);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test minutes") {
        Time::RTCTime temp(0, 59, 0, 1, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3540);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test hours") {
        Time::RTCTime temp(0, 0, 23, 1, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(82800);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test days") {
        Time::RTCTime temp(0, 0, 0, 1, 31, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(2592000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test months") {
        Time::RTCTime temp(0, 0, 0, 1, 1, 12, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(28944000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test years") {
        Time::RTCTime temp(0, 0, 0, 1, 1, 1, 99);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3124224000);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test lower bound") {
        Time::RTCTime temp(0, 0, 0, 1, 1, 1, 0);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(0);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }

    SECTION("Test upper bound") {
        Time::RTCTime temp(59, 59, 23, 0, 31, 12, 99);
        Time::RTCTime temp2;
        temp2.setTotalSeconds(3155759999);

        REQUIRE(temp.getTotalSeconds() == temp2.getTotalSeconds());
    }
}

TEST_CASE("RTCTime math") {
    Time::RTCTime temp(0, 0, 0, 1, 1, 1, 0);
    Time::RTCTime temp2(30, 0, 0, 1, 1, 1, 0);
    Time::RTCTime temp3(0, 30, 0, 1, 1, 1, 0);
    Time::RTCTime temp4(0, 0, 10, 1, 1, 1, 0);
    Time::RTCTime temp5(0, 0, 0, 1, 26, 1, 0);
    Time::RTCTime temp6(0, 0, 0, 1, 1, 5, 0);
    Time::RTCTime temp7(0, 0, 0, 1, 1, 1, 48);
    Time::RTCTime temp8(24, 56, 13, 1, 6, 2, 1);

    SECTION("Addition") {
        REQUIRE(temp + temp2 == 30);
        REQUIRE(temp2 + temp3 == 1830);
        REQUIRE(temp3 + temp4 == 37800);
        REQUIRE(temp4 + temp5 == 2196000);
        REQUIRE(temp5 + temp6 == 12614400);
        REQUIRE(temp6 + temp7 == 1525219200);
        REQUIRE(temp7 + temp8 == 1549547784);
    }

    SECTION("Subtraction") {
        REQUIRE(temp - temp2 == -30);
        REQUIRE(temp - temp3 == -1800);
        REQUIRE(temp - temp4 == -36000);
        REQUIRE(temp - temp5 == -2160000);
        REQUIRE(temp - temp6 == -10454400);
        REQUIRE(temp - temp7 == -1514764800);
        REQUIRE(temp - temp8 == -34782984);
    }

    SECTION("Addition equals") {
        temp += temp2;
        REQUIRE(temp.getTotalSeconds() == 30);
        temp += temp3;
        REQUIRE(temp.getTotalSeconds() == 1830);
        temp += temp4;
        REQUIRE(temp.getTotalSeconds() == 37830);
        temp += temp5;
        REQUIRE(temp.getTotalSeconds() == 2197830);
        temp += temp6;
        REQUIRE(temp.getTotalSeconds() == 12652230);
        temp += temp7;
        REQUIRE(temp.getTotalSeconds() == 1527417030);
        temp += temp8;
        REQUIRE(temp.getTotalSeconds() == 1562200014);
    }

    SECTION("Subtraction equals") {
        temp.setTotalSeconds(2000000000);
        temp -= temp2;
        REQUIRE(temp.getTotalSeconds() == 1999999970);
        temp -= temp3;
        REQUIRE(temp.getTotalSeconds() == 1999998170);
        temp -= temp4;
        REQUIRE(temp.getTotalSeconds() == 1999962170);
        temp -= temp5;
        REQUIRE(temp.getTotalSeconds() == 1997802170);
        temp -= temp6;
        REQUIRE(temp.getTotalSeconds() == 1987347770);
        temp -= temp7;
        REQUIRE(temp.getTotalSeconds() == 472582970);
        temp -= temp8;
        REQUIRE(temp.getTotalSeconds() == 437799986);
    }
}
