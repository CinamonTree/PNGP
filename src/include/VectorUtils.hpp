#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>

class VectorUtils {
    public:
    /** Gets subset of vector in range [from, to).
     *
     *@param input Input vector
     *@param from Start index (inclusive)
     *@param to End index (exclusive)
     *@return Subset of vector as NEW vector
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
                "Cannot get subset with starting index higher than ending index. Given: from " +
                std::to_string(from) + " to " + std::to_string(to));

        return std::vector<T>(
            input.begin() + from,
            input.begin() + to
        );
    }
};