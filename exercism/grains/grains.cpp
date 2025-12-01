#include "grains.hpp"

namespace grains
{

unsigned long long square(int number)
{
    unsigned long long result=1;

    for (int i = 1; i < number; i++)
        result = result * 2;

    return result;
}

unsigned long long total()
{
    unsigned long long total = 0;

    for (int i=1; i<=64; i++)
        total = total + square(i);

    return total;
}

}