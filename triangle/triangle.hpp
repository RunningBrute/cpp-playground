#pragma once

#include <set>
#include <algorithm>
#include <stdexcept>

namespace triangle
{

enum class flavor
{
    equilateral,
    isosceles,
    scalene
};

flavor kind(double s1, double s2, double s3);

}  // namespace triangle