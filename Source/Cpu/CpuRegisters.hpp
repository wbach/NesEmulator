#pragma once
#include <cstdint>

namespace Nes
{
struct CpuRegisters
{
    uint8_t accumulator     = 0x00;
    uint8_t x               = 0x00;
    uint8_t y               = 0x00;
    uint8_t status          = 0x00;
};
}  // namespace Nes
