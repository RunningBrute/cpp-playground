#include "triangle.hpp"

namespace triangle
{

flavor kind(double side1, double side2, double side3)
{
    std::array<double, 3> sides{side1, side2, side3};

    auto minSide = std::min_element(sides.begin(), sides.end());

    if (*minSide <= 0)
    {
        throw std::domain_error("too small sides");
    }

    std::sort(sides.begin(), sides.end(), std::greater<double>());

    double a = sides[2];
    double b = sides[1];
    double c = sides[0];

    if (c > a + b)
    {
        throw std::domain_error("violating triangle inequality");
    }

    if ((side1 == side2) & (side2 == side3))
        return flavor::equilateral;
    else if ((side1 == side2) || (side2 == side3) || (side1 == side3))
        return flavor::isosceles;
    return flavor::scalene;
}

}  // namespace triangle