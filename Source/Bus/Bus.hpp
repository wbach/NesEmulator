#pragma once
#include "IBus.hpp"
#include <array>

namespace Nes
{
class Bus : public IBus
{
public:
    Bus();
    void write(Address, Data) override;
    uint8_t read(Address) override;

private:
    std::array<Data, 64 * 1024> ram_;
};
}  // namespace Nes
