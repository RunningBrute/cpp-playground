#include <gtest/gtest.h>
#include "raindrops.hpp"

TEST(Raindrops, one_yields_itself)
{
    EXPECT_TRUE("1" == raindrops::convert(1));
}

TEST(Raindrops, three_yields_pling)
{
    EXPECT_TRUE("Pling" == raindrops::convert(3));
}

TEST(Raindrops, five_yields_plang)
{
    EXPECT_TRUE("Plang" == raindrops::convert(5));
}

TEST(Raindrops, seven_yields_plong)
{
    EXPECT_TRUE("Plong" == raindrops::convert(7));
}

TEST(Raindrops, six_yields_pling)
{
    EXPECT_TRUE("Pling" == raindrops::convert(6));
}

TEST(Raindrops, nine_yields_pling)
{
    EXPECT_TRUE("Pling" == raindrops::convert(9));
}

TEST(Raindrops, ten_yields_plang)
{
    EXPECT_TRUE("Plang" == raindrops::convert(10));
}

TEST(Raindrops, fourteen_yields_plong)
{
    EXPECT_TRUE("Plong" == raindrops::convert(14));
}

TEST(Raindrops, fifteen_yields_plingplang)
{
    EXPECT_TRUE("PlingPlang" == raindrops::convert(15));
}

TEST(Raindrops, twenty_one_yields_plingplong)
{
    EXPECT_TRUE("PlingPlong" == raindrops::convert(21));
}

TEST(Raindrops, twenty_five_yields_plang)
{
    EXPECT_TRUE("Plang" == raindrops::convert(25));
}

TEST(Raindrops, thirty_five_yields_plangplong)
{
    EXPECT_TRUE("PlangPlong" == raindrops::convert(35));
}

TEST(Raindrops, forty_nine_yields_plong)
{
    EXPECT_TRUE("Plong" == raindrops::convert(49));
}

TEST(Raindrops, fifty_two_yields_itself)
{
    EXPECT_TRUE("52" == raindrops::convert(52));
}

TEST(Raindrops, one_hundred_five_yields_plingplangplong)
{
    EXPECT_TRUE("PlingPlangPlong" == raindrops::convert(105));
}

TEST(Raindrops, big_prime_yields_itself)
{
    EXPECT_TRUE("12121" == raindrops::convert(12121));
}