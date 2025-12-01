#include <gtest/gtest.h>
#include "leap.hpp"

TEST(Leap, not_divisible_by_4)
{
    EXPECT_FALSE(leap::is_leap_year(2015));
}

TEST(Leap, divisible_by_2_not_divisible_by_4)
{
    EXPECT_FALSE(leap::is_leap_year(1970));
}

TEST(Leap, divisible_by_4_not_divisible_by_100)
{
    EXPECT_TRUE(leap::is_leap_year(1996));
}

TEST(Leap, divisible_by_100_not_divisible_by_400)
{
    EXPECT_FALSE(leap::is_leap_year(2100));
}

TEST(Leap, divisible_by_400)
{
    EXPECT_TRUE(leap::is_leap_year(2000));
}

TEST(Leap, divisible_by_200_not_divisible_by_400)
{
    EXPECT_FALSE(leap::is_leap_year(1800));
}