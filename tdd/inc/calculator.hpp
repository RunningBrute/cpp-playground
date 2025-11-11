#pragma once
#include <vector>
#include <stdexcept>
#include <cmath>

class Calculator
{
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(double a, double b);
    double power(double base, double exponent);
    double average(const std::vector<int>& numbers);
};
