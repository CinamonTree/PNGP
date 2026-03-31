#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>

class VectorUtils {
    public:
    /* Gets subset of vector with boundry included.
    *
    * @param fromIndex from boundary index
    * @param toIndex to boundary index
    * @return Subset of vector as NEW vector
    */
    template <typename T>
    static std::vector<T> getSubset( const std::vector<T>& input, 
                                     size_t fromIndex,
                                     size_t toIndex
                                   )
    {
        if (toIndex >= input.size()) 
            throw std::runtime_error(
                "Cannot take subset with index grater or equal to set size. Given: " + std::to_string(toIndex)
            );
        if (fromIndex > toIndex)
            throw std::runtime_error("Cannot get subset with starting index higher than ending index. Given: from " + std::to_string(fromIndex) + " to " + std::to_string(toIndex));
        
        return std::vector<T>(
            input.begin() + fromIndex,
            input.begin() + toIndex + 1
        );
    }
};