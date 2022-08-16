#include "leap.hpp"

namespace leap
{

bool is_leap_year(int year)
{
    const bool is_div_by_4 = year % 4 == 0;
    const bool is_div_by_100 = year % 100 == 0;
    const bool is_div_by_400 = year % 400 == 0;
    
    if (is_div_by_4)
    {
        if (is_div_by_400)
        {
            return true;
        }
        if (is_div_by_100)
        {
            return false;
        }
        return true;
    }
    return false;
}

}