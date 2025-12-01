#include "reverse_string.hpp"

namespace reverse_string
{

std::string reverse_string(std::string str)
{
    std::reverse(str.begin(), str.end());
    return str;
}

} // namespace reverse_string