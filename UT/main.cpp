#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct DummyStruct : public ::testing::Test
{
    bool a = true;
};

TEST_F(DummyStruct, dummyTest)
{
    EXPECT_TRUE(true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    auto result = RUN_ALL_TESTS();
    return result;
}