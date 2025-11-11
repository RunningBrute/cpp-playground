#include "calculator.hpp"

int Calculator::add(int a, int b)
{
    return a + b;
}

int Calculator::subtract(int a, int b)
{
    return a - b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}

double Calculator::divide(double a, double b)
{
    if (b == 0.0)
        throw std::invalid_argument("Division by zero");
    return a / b;
}

double Calculator::power(double base, double exponent)
{
    return std::pow(base, exponent);
}

double Calculator::average(const std::vector<int>& numbers)
{
    if (numbers.empty())
        throw std::invalid_argument("Empty vector passed to average()");
    
    double sum = 0.0;
    for (int n : numbers)
        sum += n;
    return sum / numbers.size();
}
