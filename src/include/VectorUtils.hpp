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
    /** Converts vector of 4 x uint8 into 
     *  single uint32 with most significant bit ordering.
     *@param input Vector of length exacly 4 of uint8 values.
     *@return Returns unsigned integer with 32 bit size
     */
    static uint32_t toUInt32BE( const std::vector<uint8_t>& input )
    {
        if (input.size() != 4)
            throw std::invalid_argument(
                "Vector of uint8 must be exactly length 4 to convert into uint32.");
        return
            (uint32_t(input[0]) << 24) |
            (uint32_t(input[1]) << 16) |
            (uint32_t(input[2]) << 8)  |
            (uint32_t(input[3]));
    }
};