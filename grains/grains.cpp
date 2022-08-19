#include "grains.hpp"

namespace grains
{

unsigned long long square(int number)
{
    int result=1;
    for (int i = 1; i < number; i++)
    {
        result = result * 2;
    }
    return result;
}

unsigned long long total()
{
    return square(64);
}

}