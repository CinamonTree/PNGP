#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>

class VectorUtils {
    public:
    /** Gets subset of vector in range [from, to).
     *@param input Input vector
     *@param from Start index (inclusive)
     *@param to End index (exclusive)
     *@return Subset of vector as NEW vector.
     */
    template <typename T>
    static std::vector<T> getSubset(
        const std::vector<T>& input,
        size_t from,
        size_t to
    )
    {
        if (to > input.size())
            throw std::runtime_error(
                "Cannot take subset with index greater than set size. Given: " + std::to_string(to));

        if (from > to)
            throw std::runtime_error(
                "Cannot get subset with starting index"
                "higher than ending index. Given: from "
                std::to_string(from) " to " std::to_string(to));

        return std::vector<T>(
            input.begin() + from,
            input.begin() + to
        );
    }
    /** Converts vector of 4 x uint8 into 
     *  single uint32 with most significant bit ordering.
     *@param input Vector of length exacly 4 of uint8 values.
     *@return Returns unsinged integer with 32 bit size
     */
    static uint32_t toUInt32_MSB( const std::vector<uint8_t>& input )
    {
        if (input.size() != 4)
            throw std::invalid_argument(
                "Vector of uint8 must be exacly length 4 to convert into uint32.");
        return
            (uint32_t(input[0]) << 24) |
            (uint32_t(input[1]) << 16) |
            (uint32_t(input[2]) << 8)  |
            (uint32_t(input[3]));
    }

};