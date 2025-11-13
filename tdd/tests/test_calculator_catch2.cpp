#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "calculator.hpp"
#include <vector>

using Catch::Approx;

TEST_CASE("Calculator basic operations", "[calculator]")
{
    Calculator calc;

    SECTION("Addition works")
    {
        REQUIRE(calc.add(2, 3) == 5);
        REQUIRE(calc.add(-1, 5) == 4);
    }

    SECTION("Subtraction works")
    {
        REQUIRE(calc.subtract(10, 4) == 6);
        REQUIRE(calc.subtract(-5, -2) == -3);
    }

    SECTION("Multiplication works")
    {
        REQUIRE(calc.multiply(3, 2) == 6);
        REQUIRE(calc.multiply(-3, 2) == -6);
        REQUIRE(calc.multiply(0, 10) == 0);
    }

    SECTION("Division works")
    {
        REQUIRE(calc.divide(10, 2) == Approx(5.0));
        REQUIRE(calc.divide(-9, 3) == Approx(-3.0));
    }

    SECTION("Division by zero throws")
    {
        REQUIRE_THROWS_AS(calc.divide(10, 0), std::invalid_argument);
    }

    SECTION("Power works correctly")
    {
        REQUIRE(calc.power(2, 3) == Approx(8.0));
        REQUIRE(calc.power(5, 0) == Approx(1.0));
        REQUIRE(calc.power(9, 0.5) == Approx(3.0));
    }

    SECTION("Average works")
    {
        REQUIRE(calc.average({1, 2, 3, 4, 5}) == Approx(3.0));
        REQUIRE(calc.average({10}) == Approx(10.0));
    }

    SECTION("Average of empty vector throws")
    {
        REQUIRE_THROWS_AS(calc.average({}), std::invalid_argument);
    }
}
