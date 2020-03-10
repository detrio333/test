#include <sstream>

#include "words.h"

std::string deletePunct(const std::string& text)
{
    std::string newText;
    for (auto& ch : text)
    {
        if (!ispunct(ch))
            newText += ch;
        else
            newText += " ";
    }
    return newText;
}

std::unordered_map<unsigned int, unsigned int> calcWordLenghts(const std::string& text)
{
    std::stringstream stream(deletePunct(text));
    std::unordered_map<unsigned int, unsigned int> counter;
    
    std::string word;
    while (stream >> word)
    {
        counter[word.size()] += 1;
    }

    return counter;
}