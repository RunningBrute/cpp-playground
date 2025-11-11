#include <catch2/catch_test_macros.hpp>
#include "calculator.hpp"

TEST_CASE("Calculator basic operations", "[calculator]")
{
    Calculator calc;

    SECTION("Addition works")
    {
        REQUIRE(calc.add(2, 3) == 5);
    }

    SECTION("Subtraction works")
    {
        REQUIRE(calc.subtract(10, 4) == 6);
    }

    SECTION("Negative numbers")
    {
        REQUIRE(calc.add(-2, -3) == -5);
        REQUIRE(calc.subtract(-5, -2) == -3);
    }
}
