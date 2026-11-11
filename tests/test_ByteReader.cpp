#include <gtest/gtest.h>

#include "ByteReader.hpp"

TEST(ByteReaderTest, ReadsBytesInOrder)
{
    const std::vector<uint8_t> bytes = {0x00, 0x80, 0xFF};
    ByteReader reader(bytes);

    EXPECT_EQ(reader.readU8(), 0x00);
    EXPECT_EQ(reader.readU8(), 0x80);
    EXPECT_EQ(reader.readU8(), 0xFF);
    EXPECT_THROW(reader.readU8(), std::out_of_range);
}

TEST(ByteReaderTest, ReadsU32InBigEndianOrderAndAdvancesFourBytes)
{
    // Keep another four bytes available so the cursor regression fails an
    // assertion without reading outside the buffer.
    const std::vector<uint8_t> bytes = {0x89, 0xAB, 0xCD, 0xEF,
                                      0x12, 0x34, 0x56, 0x78};
    ByteReader reader(bytes);

    EXPECT_EQ(reader.readU32BE(), 0x89ABCDEFu);
    EXPECT_EQ(reader.readU8(), 0x12);
}

TEST(ByteReaderTest, RejectsTruncatedU32WithoutConsumingBytes)
{
    const std::vector<uint8_t> bytes = {0x12, 0x34, 0x56};
    ByteReader reader(bytes);

    EXPECT_THROW(reader.readU32BE(), std::out_of_range);
    EXPECT_EQ(reader.readU8(), 0x12);
}

TEST(ByteReaderTest, MatchingRequiredBytesAdvanceCursor)
{
    const std::vector<uint8_t> bytes = {0x50, 0x4E, 0x47, 0x42};
    const uint8_t expected[] = {0x50, 0x4E, 0x47};
    ByteReader reader(bytes);

    EXPECT_NO_THROW(reader.requireBytes(expected, 3, "Invalid signature"));
    EXPECT_EQ(reader.readU8(), 0x42);
}

TEST(ByteReaderTest, MismatchingRequiredBytesDoNotConsumeInput)
{
    const std::vector<uint8_t> bytes = {0x50, 0x4E};
    const uint8_t expected[] = {0x50, 0x47};
    ByteReader reader(bytes);

    EXPECT_THROW(reader.requireBytes(expected, 2, "Invalid signature"),
                 std::runtime_error);
    EXPECT_EQ(reader.readU8(), 0x50);
}

TEST(ByteReaderTest, RejectsTruncatedRequiredBytesWithoutConsumingInput)
{
    const std::vector<uint8_t> bytes = {0x50};
    const uint8_t expected[] = {0x50, 0x4E};
    ByteReader reader(bytes);

    EXPECT_THROW(reader.requireBytes(expected, 2, "Invalid signature"),
                 std::out_of_range);
    EXPECT_EQ(reader.readU8(), 0x50);
}
