#pragma once

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

class ByteReader
{
   private:
    const uint8_t* cursor;
    const uint8_t* end;

   public:
    explicit ByteReader(const std::vector<uint8_t>& bytes)
        : cursor(bytes.data()), end(bytes.data() + bytes.size())
    {
    }
    uint32_t readU32BE()
    {
        require(4);
        const uint32_t value = (static_cast<uint32_t>(cursor[0]) << 24)
                               | (static_cast<uint32_t>(cursor[1]) << 16)
                               | (static_cast<uint32_t>(cursor[2]) << 8)
                               | static_cast<uint32_t>(cursor[3]);
        cursor += 4;
        return value;
    }
    uint8_t readU8()
    {
        require(1);
        return *cursor++;
    }
    void expectBytes(const uint8_t* expected, size_t count,
                     const char* errorMessage)
    {
        require(count);
        if (std::memcmp(cursor, expected, count) != 0)
            throw std::runtime_error(errorMessage);
        cursor += count;
    }

   private:
    void require(size_t count) const
    {
        if (static_cast<size_t>(end - cursor) < count)
        {
            throw std::out_of_range("Out of range access.");
        }
    }
};