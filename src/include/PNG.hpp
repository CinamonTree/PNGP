#include <vector>
#include <cstdint>
#include <stdexcept>

#include "VectorUtils.hpp"

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
    PNG fromRaw(const std::vector<uint8_t>& bytesArray) 
    {
        const size_t IHDR_START = 8;

        auto signaturBytes = VectorUtils::getSubset(bytesArray, 0, 8);
        if (!isSignatureValid(signaturBytes)) 
            throw std::runtime_error("Sigranure of given PNG file is incorect.");

        chunk IHDR;
        IHDR.chunkType = ChunkType::IHDR;
        IHDR.length = VectorUtils::toUInt32BE(VectorUtils::getSubset(bytesArray, IHDR_START, 4));
        if (IHDR.length != 13)
            throw std::runtime_error("Length of PNG header chunk is incorect. Given:" + IHDR.length);
            
        IHDR.data = VectorUtils::getSubset(bytesArray, IHDR_START + 4, IHDR.length);
        this->width = VectorUtils::toUInt32BE(VectorUtils::getSubset(IHDR.data, 0, 4));
        this->height = VectorUtils::toUInt32BE(VectorUtils::getSubset(IHDR.data, 4, 4));
        this->bitDepth = IHDR.data[8];
        this->colorType = IHDR.data[9];
        this->compressionMethod = IHDR.data[10];
        this->filterMethod = IHDR.data[11];
        this->interlaceMethod = IHDR.data[12];
    };
private:
    PNG() {};
    bool isSignatureValid(const std::vector<uint8_t>& signature) const
    {
        if (signature.size() < 8) return false;
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