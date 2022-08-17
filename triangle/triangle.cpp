#include "triangle.hpp"

namespace triangle
{

flavor kind(double side1, double side2, double side3)
{
    std::array<double, 3> sides{side1, side2, side3};
    std::sort(sides.begin(), sides.end());

    if (side1 <= 0 || side2 <= 0 || side3 <=0)
    {
        throw std::domain_error("too small sides");
    }



    if (side1 == side2 & side2 == side3)
        return flavor::equilateral;
    else if (side1 == side2 || side2 == side3 || side1 == side3)
        return flavor::isosceles;
    return flavor::scalene;
}

}  // namespace triangle