#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    auto result = RUN_ALL_TESTS();
    return result;
}
