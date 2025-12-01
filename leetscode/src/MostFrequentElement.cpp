#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

// Task: Find the Most Frequent Element
// Write a function that finds the most frequently occurring element
// in a given vector of integers. If there is a tie,
// return the smallest of the most frequently occurring elements.
//
// Example Input:  {1, 1, 2, 3};
// Example Output: Most frequent element: 1

namespace MostFrequentElement
{

using InputNumbers = std::vector<int>;
using Occurrences = std::unordered_map<int, int>;

int findMostFrequentElement(const InputNumbers& nums)
{
    if (nums.empty())
    {
        throw std::logic_error("Input vector is empty");
    }

    Occurrences occurrences;
    for (int num : nums)
    {
        occurrences[num]++;
    }

    auto result = std::max_element(occurrences.begin(), occurrences.end(),
        [](const auto& a, const auto& b) {
            return (a.second < b.second) || 
                   (a.second == b.second && a.first > b.first);
        });

    return result->first;
}

TEST_CASE("Throw if input vector is empty", "[MostFrequentElement]")
{
    InputNumbers emptyVector;
    REQUIRE_THROWS_AS(findMostFrequentElement(emptyVector), std::logic_error);
}

TEST_CASE("In input vector contains one element then return this element", "[MostFrequentElement]")
{
    REQUIRE(findMostFrequentElement({42}) == 42);
}

TEST_CASE("Find the most frequent element when no tie", "[MostFrequentElement]")
{
    REQUIRE(findMostFrequentElement({1, 2, 3, 3}) == 3);
}

TEST_CASE("In case of a tie, most frequent element is a smaller one", "[MostFrequentElement]")
{
    REQUIRE(findMostFrequentElement({1, 1, 2, 3, 3}) == 1);
}

} // namespace MostFrequentElement
