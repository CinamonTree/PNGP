#include <vector>
#include <cstdint>
#include <stdexcept>

#include "ByteUtils.hpp"

class PNG 
{
private:
    enum class ChunkType 
    {
      IHDR,
      PLTE,
      IDAT,
      IEND
    };
    struct chunk 
    {
        uint32_t length;
        ChunkType chunkType;
        std::vector<uint8_t> data;
        uint32_t CRC;
    };
    std::vector<uint8_t> pixelData;
    uint32_t width;
    uint32_t height;
    uint8_t bitDepth;
    uint8_t colorType;
    uint8_t compressionMethod;
    uint8_t filterMethod;
    uint8_t interlaceMethod;
public:
    PNG fromRaw(const std::vector<uint8_t>& PNGBytes) 
    {
        const uint8_t* PNGCursor = PNGBytes.data();
        const size_t IHDR_START = 8;

        if (!isSignatureValid(PNGCursor)) 
            throw std::runtime_error("Sigranure of given PNG file is incorect.");

        PNGCursor += IHDR_START;

        this->width = ByteUtils::readU32BE(PNGCursor);
        this->height = ByteUtils::readU32BE(PNGCursor);
        this->bitDepth = ByteUtils::readU8(PNGCursor);
        this->colorType = ByteUtils::readU8(PNGCursor);
        this->compressionMethod = ByteUtils::readU8(PNGCursor);
        this->filterMethod = ByteUtils::readU8(PNGCursor);
        this->interlaceMethod = ByteUtils::readU8(PNGCursor);
    };
private:
    PNG() {};
    bool isSignatureValid(const uint8_t* signature) const
    {
        return 
            signature[0] == 0x89 &&
            signature[1] == 0x50 &&
            signature[2] == 0x4E &&
            signature[3] == 0x47 &&
            signature[4] == 0x0D &&
            signature[5] == 0x0A &&
            signature[6] == 0x1A &&
            signature[7] == 0x0A;
    }
};