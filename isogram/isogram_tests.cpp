#include <gtest/gtest.h>
#include "isogram.hpp"

TEST(IsogramTest, EmptyStringIsIsogram)
{
    const bool isIsogram = isogram::is_isogram("");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, IsogramWithOnlyLowerCaseCharacters)
{
    const bool isIsogram = isogram::is_isogram("isogram");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, WordWithOneDuplicatedCharacter)
{
    const bool isIsogram = isogram::is_isogram("eleven");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, WordWithOneDuplicatedCharacterFromTheEndOfTheAlphabet)
{
    const bool isIsogram = isogram::is_isogram("zzyzx");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, LongestReportedEnglishIsogram)
{
    const bool isIsogram = isogram::is_isogram("subdermatoglyphic");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, WordWithDuplicatedCharacterInMixedCase)
{
    const bool isIsogram = isogram::is_isogram("Alphabet");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, WordWithDuplicatedCharacterInMixedCaseLowercaseFirst)
{
    const bool isIsogram = isogram::is_isogram("alphAbet");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, HypotheticalIsogrammicWordWithHyphen)
{
    const bool isIsogram = isogram::is_isogram("thumbscrew-japingly");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, HypotheticalWordWithDuplicatedCharacterFollowingHyphen)
{
    const bool isIsogram = isogram::is_isogram("thumbscrew-jappingly");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, IsogramWithDuplicatedHyphen)
{
    const bool isIsogram = isogram::is_isogram("six-year-old");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, MadeUpNameThatIsAnIsogram)
{
    const bool isIsogram = isogram::is_isogram("Emily Jung Schwartzkopf");
    EXPECT_TRUE(isIsogram);
}

TEST(IsogramTest, DuplicatedCharacterInTheMiddle)
{
    const bool isIsogram = isogram::is_isogram("accentor");
    EXPECT_FALSE(isIsogram);
}

TEST(IsogramTest, SameFirstAndLastCharacters)
{
    const bool isIsogram = isogram::is_isogram("angola");
    EXPECT_FALSE(isIsogram);
}