#include "triangle.hpp"

namespace triangle
{

bool compareFloatNumbers(double a, double b)
{
    if (abs(a - b) < 1e-9) return true;
    else return false;
}

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

    //if (!compareFloatNumbers(std::pow(c, 2), (std::pow(a, 2) + std::pow(b, 2))))
    //{
    //    throw std::domain_error("");
    //}

    if ((side1 == side2) & (side2 == side3))
        return flavor::equilateral;
    else if ((side1 == side2) || (side2 == side3) || (side1 == side3))
        return flavor::isosceles;
    return flavor::scalene;
}

}  // namespace triangle