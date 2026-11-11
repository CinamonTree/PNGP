#pragma once

#include <cstdint>
#include <vector>

class PNG
{
   public:
    static constexpr uint8_t IHDR_CHUNK_LENGTH[4] = {0x00, 0x00, 0x00, 0x0D};
    static constexpr uint8_t IHDR_TYPE[4] = {0x49, 0x48, 0x44, 0x52};
    static constexpr uint8_t PNG_SIGNATURE[8] = {0x89, 0x50, 0x4E, 0x47,
                                                 0x0D, 0x0A, 0x1A, 0x0A};

    std::vector<uint8_t> pixelData;
    uint32_t width = 0;
    uint32_t height = 0;
    uint8_t bitDepth = 0;
    uint8_t colorType = 0;
    uint8_t compressionMethod = 0;
    uint8_t filterMethod = 0;
    uint8_t interlaceMethod = 0;

    static PNG fromRaw(const std::vector<uint8_t>& bytes);

   private:
    PNG();
};
