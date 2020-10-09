#pragma once
#include <gmock/gmock.h>
#include "Bus/IBus.hpp"

namespace Nes
{
class BusMock : public IBus
{
public:
    MOCK_METHOD(void, write, (Address, Data), (override));
    MOCK_METHOD(uint8_t, read, (Address), (override));
};
}  // namespace Nes
