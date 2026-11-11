#include "PNG.hpp"

#include "ByteReader.hpp"

PNG::PNG()
{
}

PNG
PNG::fromRaw(const std::vector<uint8_t>& bytes)
{
    ByteReader byteReader(bytes);
    PNG pngObject;

    byteReader.requireBytes(PNG_SIGNATURE, 8, "PNG signature is incorrect.");
    byteReader.requireBytes(IHDR_CHUNK_LENGTH, 4,
                            "PNG signature is incorrect.");
    byteReader.requireBytes(IHDR_TYPE, 4, "Type of IHDR chunk is incorect.");

    pngObject.width = byteReader.readU32BE();
    pngObject.height = byteReader.readU32BE();
    pngObject.colorType = byteReader.readU8();
    pngObject.compressionMethod = byteReader.readU8();
    pngObject.filterMethod = byteReader.readU8();
    pngObject.interlaceMethod = byteReader.readU8();
}
