#include <vector>
#include <cstdint>

class PNG {
    private:
    enum class ChunkType {
      IHDR,
      PLTE,
      IDAT,
      IEND,
      bKGD,
      cHRM,
      cICP,
      dSIG,
      eXIf,
      gAMA,
      hIST,
      iCCP,
      iTXt,
      pHYs,
      sBIT,
      sPLT,
      sRGB,
      sTER,
      tEXt,
      tIME,
      tRNS,
      zTXt
    };
    struct chunk {
        uint8_t length[4];
        ChunkType chunkType;
        uint8_t* data;
        uint8_t CRC[4];
    };
    PNG() {};
    public:
    PNG fromRaw(const std::vector<uint8_t>& bytesArray) 
    {

    };
    private:
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