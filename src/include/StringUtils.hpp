#include <cctype>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class StringUtils
{
   public:
    static std::string toLower(const std::string& input)
    {
        std::string output = input;

        for (char& c : output)
        {
            c = std::tolower(static_cast<unsigned char>(c));
        }

        return output;
    }
    static std::string toUpper(const std::string& input)
    {
        std::string output = input;

        for (char& c : output)
        {
            c = std::toupper(static_cast<unsigned char>(c));
        }

        return output;
    }
    static std::unordered_map<char, size_t> countChars(const std::string& input)
    {
        std::unordered_map<char, size_t> frequencies;

        for (char c : input)
        {
            frequencies[c]++;
        }

        return frequencies;
    }
    static std::string toHexEscaped(const std::vector<std::byte>& input)
    {
        std::ostringstream output;

        for (std::byte b : input)
        {
            output << "\\0x" << std::uppercase << std::hex << std::setw(2)
                   << std::setfill('0') << std::to_integer<unsigned int>(b);
        }

        return output.str();
    }
};