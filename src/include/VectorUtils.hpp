#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>

class VectorUtils 
{
public:
    /** Returns a subset of the vector.
     *@param input Input vector
     *@param from Start index (inclusive)
     *@param length Length of subset
     *@return Subset of vector as a NEW vector.
     */
    template <typename T>
    static std::vector<T> getSubset(
        const std::vector<T>& input,
        size_t from,
        size_t length
    )
    {
        if (from > input.size())
            throw std::out_of_range(
                "Starting index out of bounds. Given: " +
                std::to_string(from));

        if (length > input.size() - from)
            throw std::out_of_range(
            "Subset is too long. from: " + std::to_string(from) +
            " length: " + std::to_string(length));

        return std::vector<T>(
            input.begin() + from,
            input.begin() + from + length
        );
    }
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
};