#include <gtest/gtest.h>

#include <cstdint>
#include <vector>

#include "VectorUtils.hpp"

TEST(VectorUtilsGetSubset, ReturnsCorrectMiddleSubset)
{
    std::vector<int> input{10, 20, 30, 40, 50};

    auto result = VectorUtils::getSubset(input, 1, 4);

    std::vector<int> expected{20, 30, 40};
    EXPECT_EQ(result, expected);
}

TEST(VectorUtilsGetSubset, ReturnsWholeVector)
{
    std::vector<int> input{10, 20, 30};

    auto result = VectorUtils::getSubset(input, 0, 3);

    EXPECT_EQ(result, input);
}

TEST(VectorUtilsGetSubset, ReturnsEmptyRangeWhenFromEqualsTo)
{
    std::vector<int> input{10, 20, 30};

    auto result = VectorUtils::getSubset(input, 1, 1);

    std::vector<int> expected{};
    EXPECT_EQ(result, expected);
}

TEST(VectorUtilsGetSubset, ReturnsFirstElement)
{
    std::vector<int> input{10, 20, 30};

    auto result = VectorUtils::getSubset(input, 0, 1);

    std::vector<int> expected{10};
    EXPECT_EQ(result, expected);
}

TEST(VectorUtilsGetSubset, ReturnsLastElement)
{
    std::vector<int> input{10, 20, 30};

    auto result = VectorUtils::getSubset(input, 2, 3);

    std::vector<int> expected{30};
    EXPECT_EQ(result, expected);
}

TEST(VectorUtilsGetSubset, ThrowsWhenToIndexIsOutOfRange)
{
    std::vector<int> input{10, 20, 30};

    EXPECT_THROW(VectorUtils::getSubset(input, 0, 4), std::runtime_error);
}

TEST(VectorUtilsGetSubset, ThrowsWhenFromIndexIsGreaterThanToIndex)
{
    std::vector<int> input{10, 20, 30};

    EXPECT_THROW(VectorUtils::getSubset(input, 2, 1), std::runtime_error);
}

TEST(VectorUtilsGetSubset, ReturnsEmptyVectorForEmptyInputAndEmptyRange)
{
    std::vector<int> input{};

    std::vector<int> expected{};
    EXPECT_EQ(VectorUtils::getSubset(input, 0, 0), expected);
}
