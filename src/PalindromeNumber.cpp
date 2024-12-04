#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

// Task: Given an integer x, return true if x is a palindrome, and false otherwise.
//
// Example 1:
//    Input: x = 121
//    Output: true
//    Explanation: 121 reads as 121 from left to right and from right to left.
//
// Example 2:
//    Input: x = -121
//    Output: false
//    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
// Example 3:
//    Input: x = 10
//    Output: false
//    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

namespace PalindromeNumber
{

bool isPalindrome(int x)
{
    const auto numberAsString = std::to_string(x);
    const auto digitsInNumber = numberAsString.size();
    auto isNumberPalindrome = true;

    for (int i = 0; i < numberAsString.size(); i++)
    {
        if (numberAsString[i] != numberAsString[digitsInNumber - i - 1])
        {
            isNumberPalindrome = false;
            break;
        }
    }

    return isNumberPalindrome;
}

TEST_CASE("Test that 11 is palindrome", "[PalindromeNumber]")
{
    REQUIRE(isPalindrome(11) == true);
}

} // namespace PalindromeNumber