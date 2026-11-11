#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

class ByteReader
{
   private:
    const uint8_t* cursor;
    const uint8_t* end;

   public:
    explicit ByteReader(const std::vector<uint8_t>& bytes);
    uint32_t readU32BE();
    uint8_t readU8();
    void requireBytes(const uint8_t* required, std::size_t count,
                      const char* errorMessage);

   private:
    void require(std::size_t count) const;
};
