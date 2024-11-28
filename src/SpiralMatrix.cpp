#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

// Task: Given an m x n matrix, return all elements of the matrix in spiral order.
//
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

namespace SpiralMatrix
{

using InputMatrix = std::vector<std::vector<int>>;
using OutputMatrix = std::vector<int>;

OutputMatrix spiralOrder(const InputMatrix& matrix)
{
    return {};
}

TEST_CASE("For empty matrix nothing to do", "[SpiralMatrix]")
{
    InputMatrix emptyMatrix;
    OutputMatrix emptyResult;
    REQUIRE(spiralOrder(emptyMatrix) == emptyResult);
}

} // namespace SpiralMatrix