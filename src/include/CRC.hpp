#include <cstdint>
#include <vector>

class CRC
{
   private:
    static uint32_t lookupTable[256];
    static bool initialized;

    static void buildLookupTable()
    {
        for (uint32_t i = 0; i < 256; i++)
        {
            uint32_t c = i;

            for (int j = 0; j < 8; j++)
            {
                if (c & 1)
                    c = (c >> 1) ^ 0xEDB88320;
                else
                    c >>= 1;
            }

            lookupTable[i] = c;
        }

        initialized = true;
    }

   public:
    static uint32_t getCrc32(const std::vector<uint8_t>& bytes)
    {
        if (!initialized) buildLookupTable();

        uint32_t crc = 0xFFFFFFFF;

        for (uint8_t byte : bytes)
        {
            uint8_t index = (crc ^ byte) & 0xFF;
            crc = (crc >> 8) ^ lookupTable[index];
        }

        return crc ^ 0xFFFFFFFF;
    }
};

uint32_t CRC::lookupTable[256];
bool CRC::initialized = false;