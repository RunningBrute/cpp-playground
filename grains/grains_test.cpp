#include <gtest/gtest.h>
#include "grains.hpp"

TEST(Grains, square_1)
{
    EXPECT_TRUE(1ULL == grains::square(1));
}

TEST(Grains, square_2)
{
    EXPECT_TRUE(2ULL == grains::square(2));
}

TEST(Grains, square_3)
{
    EXPECT_TRUE(4ULL == grains::square(3));
}

TEST(Grains, square_4)
{
    EXPECT_TRUE(8ULL == grains::square(4));
}

TEST(Grains, square_16)
{
    EXPECT_TRUE(32768ULL == grains::square(16));
}

TEST(Grains, square_32)
{
    EXPECT_TRUE(2147483648ULL == grains::square(32));
}

TEST(Grains, square_64)
{
    EXPECT_TRUE(9223372036854775808ULL == grains::square(64));
}

TEST(Grains, total)
{
    EXPECT_TRUE(18446744073709551615ULL == grains::total());
}