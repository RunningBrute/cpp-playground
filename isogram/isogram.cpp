#include "isogram.hpp"

namespace isogram
{

std::string getOnlyLetters(std::string word)
{
    std::string wordWithOnlyLetters;
    auto isLetter = [](char letter){ return std::isalpha(letter); };

    std::copy_if(
        word.begin(),
        word.end(),
        std::back_inserter(wordWithOnlyLetters),
        isLetter);
    
    return wordWithOnlyLetters;
}

std::string getLowerCaseWordWithOnlyLetters(std::string word)
{
    std::string letters = getOnlyLetters(word);
    std::transform(
        letters.begin(),
        letters.end(),
        letters.begin(),
        [](char letter){ return std::tolower(letter); }
    );
    return letters;
}

bool is_isogram(std::string word)
{
    std::string lowerCaseLetters = getLowerCaseWordWithOnlyLetters(word);

    std::set<char> singleLetters(
        lowerCaseLetters.begin(),
        lowerCaseLetters.end());

    return singleLetters.size() == lowerCaseLetters.size();
}

} // namespace isogram