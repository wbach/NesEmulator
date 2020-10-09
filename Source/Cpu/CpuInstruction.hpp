#pragma once
#include <cstdint>
#include <string>
#include <functional>

namespace Nes
{
struct CpuInstruction
{
    std::string name;
    std::function<uint8_t()> operate;
    std::function<uint8_t()> addrmode;
    uint8_t cycles = 0;
};
}  // namespace Nes
