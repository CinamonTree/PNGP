#pragma once

#include <cstdint>
#include <vector>

class CRC
{
   private:
    static uint32_t lookupTable[256];
    static bool initialized;

    static void buildLookupTable();

   public:
    static uint32_t getCrc32(const std::vector<uint8_t>& bytes);
};
