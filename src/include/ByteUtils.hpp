#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>

class ByteUtils 
{
public:
    /** Converts 4 bytes of uint8_t into single uint32_t with Big Edian
     *  and moves given pointer by 4 bytes.
     *@param input Reference pointer to byte array of uint8_t format.
     *@return Single uint32_t value.
     */
    static uint32_t readU32BE(const uint8_t*& input)
    {
        uint32_t value = 
            (uint32_t(input[0]) << 24) |
            (uint32_t(input[1]) << 16) |
            (uint32_t(input[2]) << 8)  |
            uint32_t(input[3]);

        input += 4;
        return value;
    }
    /** Read one byte from given pointer and move it to the next
     *@param input Reference pointer to byte array of uint8_t format.
     *@return Single uint8_t value.
     */
    static uint8_t readU8(const uint8_t*& input)
    {
        uint8_t value = *input;
        input += 1;
        return value;
    }
};