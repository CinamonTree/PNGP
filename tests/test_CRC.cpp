#include <gtest/gtest.h>

#include "CRC.hpp"

TEST(CRCTest, EmptyInputHasZeroCrc)
{
    EXPECT_EQ(CRC::getCrc32({}), 0u);
}

TEST(CRCTest, MatchesStandardCheckValue)
{
    const std::vector<uint8_t> bytes = {'1', '2', '3', '4', '5',
                                      '6', '7', '8', '9'};

    EXPECT_EQ(CRC::getCrc32(bytes), 0xCBF43926u);
}

TEST(CRCTest, MatchesPngIendChunkCrc)
{
    // IEND has no data, so its CRC covers only the four type bytes.
    const std::vector<uint8_t> bytes = {'I', 'E', 'N', 'D'};

    EXPECT_EQ(CRC::getCrc32(bytes), 0xAE426082u);
}
