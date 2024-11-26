#include <catch2/catch_test_macros.hpp>
#include <vector>

int findMax(const std::vector<int>& nums)
{
    return *std::max_element(nums.begin(), nums.end());
}

TEST_CASE("Find maximum in vector", "[findMax]")
{
    REQUIRE(findMax({1, 2, 3}) == 3);
    REQUIRE(findMax({-1, -2, -3}) == -1);
}