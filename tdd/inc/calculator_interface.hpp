#pragma once
#include <vector>

class ICalculator
{
    public:
    virtual int add(int a, int b) = 0;
    virtual int subtract(int a, int b) = 0;
    virtual int multiply(int a, int b) = 0;
    virtual double divide(double a, double b) = 0;
    virtual double power(double base, double exponent) = 0;
    virtual double average(const std::vector<int>& numbers) = 0;
    virtual ~ICalculator() = default;
};