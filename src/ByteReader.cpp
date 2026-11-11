#include "ByteReader.hpp"

#include <cstring>
#include <stdexcept>

ByteReader::ByteReader(const std::vector<uint8_t>& bytes)
    : cursor(bytes.data()), end(bytes.data() + bytes.size())
{
}

uint32_t
ByteReader::readU32BE()
{
    require(4);
    const uint32_t value = (static_cast<uint32_t>(cursor[0]) << 24)
                           | (static_cast<uint32_t>(cursor[1]) << 16)
                           | (static_cast<uint32_t>(cursor[2]) << 8)
                           | static_cast<uint32_t>(cursor[3]);
    cursor += 4;
    return value;
}

uint8_t
ByteReader::readU8()
{
    require(1);
    return *cursor++;
}

void
ByteReader::requireBytes(const uint8_t* required, std::size_t count,
                         const char* errorMessage)
{
    require(count);
    if (std::memcmp(cursor, required, count) != 0)
        throw std::runtime_error(errorMessage);
    cursor += count;
}

void
ByteReader::require(std::size_t count) const
{
    if (static_cast<std::size_t>(end - cursor) < count)
    {
        throw std::out_of_range("Out of range access.");
    }
}
