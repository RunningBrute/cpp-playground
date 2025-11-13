#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "calculator.hpp"

TEST(CalculatorTest, AdditionWorks)
{
    Calculator calc;

    EXPECT_TRUE(calc.add(2, 3) == 5);
    EXPECT_TRUE(calc.add(-1, 5) == 4);
}

TEST(CalculatorTest, SubtractionWorks)
{
    Calculator calc;

    EXPECT_TRUE(calc.add(2, 3) == 5);
    EXPECT_TRUE(calc.add(-1, 5) == 4);
}