#pragma once
#include "Common/Types.hpp"

namespace Nes
{
class IBus
{
public:
    ~IBus() = default;

    virtual void write(Address, Data)   = 0;
    virtual uint8_t read(Address) = 0;
};
}  // namespace Nes
