#include "raindrops.hpp"

namespace raindrops
{

std::string convert(int drops)
{
    std::string sounds;

    if (drops % 3 == 0) sounds += "Pling";
    if (drops % 5 == 0) sounds += "Plang";
    if (drops % 7 == 0) sounds += "Plong";

    if (sounds.empty()) return std::to_string(drops);
    
    return sounds;
}

}  // namespace raindrops