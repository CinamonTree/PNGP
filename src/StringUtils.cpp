#include "StringUtils.hpp"

#include <cctype>
#include <iomanip>
#include <sstream>

std::string
StringUtils::toLower(const std::string& input)
{
    std::string output = input;

    for (char& c : output)
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }

    return output;
}

std::string
StringUtils::toUpper(const std::string& input)
{
    std::string output = input;

    for (char& c : output)
    {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    return output;
}

std::unordered_map<char, std::size_t>
StringUtils::countChars(const std::string& input)
{
    std::unordered_map<char, std::size_t> frequencies;

    for (char c : input)
    {
        frequencies[c]++;
    }

    return frequencies;
}

std::string
StringUtils::toHexEscaped(const std::vector<std::byte>& input)
{
    std::ostringstream output;

    for (std::byte b : input)
    {
        output << "\\0x" << std::uppercase << std::hex << std::setw(2)
               << std::setfill('0') << std::to_integer<unsigned int>(b);
    }

    return output.str();
}
