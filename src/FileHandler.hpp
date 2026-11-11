#pragma once

#include <cstdint>
#include <string>
#include <vector>

class FileHandler
{
   public:
    static std::vector<uint8_t> getRaw(const std::string& filePath);
    static void writeRaw(const std::string& filePath,
                         const std::vector<uint8_t>& data);
};
