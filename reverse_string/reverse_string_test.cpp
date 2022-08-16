#include <gtest/gtest.h>
#include "reverse_string.hpp"

TEST(ReverseString, an_empty_string)
{
    EXPECT_TRUE("" == reverse_string::reverse_string(""));
}

TEST(ReverseString, a_word)
{
    EXPECT_TRUE("tobor" == reverse_string::reverse_string("robot"));
}

TEST(ReverseString, a_capitalized_word)
{
    EXPECT_TRUE("nemaR" == reverse_string::reverse_string("Ramen"));
}

TEST(ReverseString, a_sentence_with_punctuation)
{
    EXPECT_TRUE("!yrgnuh m'I" == reverse_string::reverse_string("I'm hungry!"));
}

TEST(ReverseString, a_palindrome)
{
   EXPECT_TRUE("racecar" == reverse_string::reverse_string("racecar"));
}