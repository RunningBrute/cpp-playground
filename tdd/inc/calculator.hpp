#pragma once
#include <stdexcept>
#include <cmath>

#include "calculator_interface.hpp"

class Calculator : public ICalculator
{
public:
    int add(int a, int b) override;
    int subtract(int a, int b) override;
    int multiply(int a, int b) override;
    double divide(double a, double b) override;
    double power(double base, double exponent) override;
    double average(const std::vector<int>& numbers) override;
    ~Calculator() = default;;
};
