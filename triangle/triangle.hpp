#pragma once

#include <set>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <bits/stdc++.h>

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