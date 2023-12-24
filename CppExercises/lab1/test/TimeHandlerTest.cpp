#include <catch2/catch_all.hpp>
#include "../TimeHandler.h"

using namespace saab::library;
static const bool format_24h{true};

TEST_CASE("TimeHandler to_string()", "[TimeHandler]")
{
    SECTION("Check to_string() for time as AM.")
    {
        TimeHandler t1(10u, 20u, 30u);
        REQUIRE(t1.to_string(format_24h) == "10:20:30");
        REQUIRE(t1.to_string(!format_24h) == "10:20:30 am");
    }

    SECTION("Check to_string() for time as PM.")
    {
        TimeHandler t1(13u, 10u, 11u);
        REQUIRE(t1.to_string(format_24h) == "13:10:11");
        REQUIRE(t1.to_string(!format_24h) == "01:10:11 pm");
    }

    SECTION("Check to_string() for midnight")
    {
        TimeHandler t1(0u, 0u, 0u);
        REQUIRE(t1.to_string(format_24h) == "00:00:00");
        REQUIRE(t1.to_string(!format_24h) == "00:00:00 am");
    }
}

TEST_CASE("TimeHandler Comparison Operators", "[TimeHandler]")
{
    TimeHandler t1(10u, 20u, 30u);
    TimeHandler t2(10u, 20u, 30u);
    TimeHandler t3(11u, 22u, 33u);

    SECTION("Equality") { REQUIRE(t1 == t2); }

    SECTION("Inequality") { REQUIRE(t1 != t3); }
}

TEST_CASE("TimeHandler increment and decrement operators", "[TimeHandler]")
{
    TimeHandler t1(12u, 59u, 59u);

    SECTION("Check operator +")
    {
        REQUIRE((t1 + 5).to_string(format_24h) == "13:00:04");
        REQUIRE(t1.to_string(format_24h) == "12:59:59");
    }

    SECTION("Check operator -")
    {
        REQUIRE((t1 - 3600).to_string(format_24h) == "11:59:59");
        REQUIRE(t1.to_string(format_24h) == "12:59:59");
    }

    SECTION("Check pre increment")
    {
        REQUIRE((++t1).to_string(format_24h) == "13:00:00");
        REQUIRE(t1.to_string(format_24h) == "13:00:00");
    }
    SECTION("Check post increment")
    {
        REQUIRE((t1++).to_string(format_24h) == "12:59:59");
        REQUIRE(t1.to_string(format_24h) == "13:00:00");
    }

    SECTION("Check pre decrement")
    {
        REQUIRE((--t1).to_string(format_24h) == "12:59:58");
        REQUIRE(t1.to_string(format_24h) == "12:59:58");
    }
    SECTION("Check post decrement")
    {
        REQUIRE((t1--).to_string(format_24h) == "12:59:59");
        REQUIRE(t1.to_string(format_24h) == "12:59:58");
    }
}