#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

class StringUtils
{
   public:
    static std::string toLower(const std::string& input);
    static std::string toUpper(const std::string& input);
    static std::unordered_map<char, std::size_t> countChars(
        const std::string& input);
    static std::string toHexEscaped(const std::vector<std::byte>& input);
};
