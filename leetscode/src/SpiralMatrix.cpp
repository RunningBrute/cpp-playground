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
//
// Constraints:
//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 10
//     -100 <= matrix[i][j] <= 100

namespace SpiralMatrix
{

using InputMatrix = std::vector<std::vector<int>>;
using OutputMatrix = std::vector<int>;

enum class ViewingDirection
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

OutputMatrix spiralOrder(const InputMatrix& matrix)
{
    const auto numberOfelements = matrix.size() * matrix[0].size();
    
    OutputMatrix result;
    result.reserve(numberOfelements);
    
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    ViewingDirection currentVievingDirection = ViewingDirection::RIGHT;

    while (result.size() < numberOfelements)
    {
        if (currentVievingDirection == ViewingDirection::RIGHT)
        {
            for (int i = left; i < right + 1; i++)
            {
                result.push_back(matrix[top][i]);
            }

            top++;
            currentVievingDirection = ViewingDirection::DOWN;
        }
        else if (currentVievingDirection == ViewingDirection::DOWN)
        {
            for (int i = top; i < bottom + 1; i++)
            {
                result.push_back(matrix[i][right]);
            }

            right--;
            currentVievingDirection = ViewingDirection::LEFT;
        }
        else if (currentVievingDirection == ViewingDirection::LEFT)
        {
            for (int i = right; i > left - 1; i--)
            {
                result.push_back(matrix[bottom][i]);
            }

            bottom--;
            currentVievingDirection = ViewingDirection::UP;
        }
        else if (currentVievingDirection == ViewingDirection::UP)
        {
            for (int i = bottom; i > top - 1; i--)
            {
                result.push_back(matrix[i][left]);
            }

            left++;
            currentVievingDirection = ViewingDirection::RIGHT;
        }
    }

    return result;
}

/*
TEST_CASE("For empty matrix nothing to do", "[SpiralMatrix]")
{
    InputMatrix emptyMatrix;
    OutputMatrix emptyResult;
    REQUIRE(spiralOrder(emptyMatrix) == emptyResult);
}
*/

TEST_CASE("Test example 1", "[SpiralMatrix]")
{
    InputMatrix matrix = {{1,2,3},{4,5,6},{7,8,9}};
    OutputMatrix expectedResult = {1,2,3,6,9,8,7,4,5};
    
    REQUIRE(spiralOrder(matrix) == expectedResult);
}

TEST_CASE("Test example 2", "[SpiralMatrix]")
{
    InputMatrix matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    OutputMatrix expectedResult = {1,2,3,4,8,12,11,10,9,5,6,7};
    
    REQUIRE(spiralOrder(matrix) == expectedResult);
}

} // namespace SpiralMatrix