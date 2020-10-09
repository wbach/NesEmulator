#include "Olc6502.hpp"
#include <iostream>
#include "Bus/IBus.hpp"

namespace Nes
{
namespace
{
CpuInstruction defaultInstruction;
}
Olc6502::Olc6502(IBus& bus)
    : bus_{bus}
{
    initInstructionTable();
}
void Olc6502::reset()
{
}
void Olc6502::interruptRequest()
{
}
void Olc6502::nonMaskableInterruptRequest()
{
}
void Olc6502::clock()
{
    if (currentInstructionCycles_ == 0)
    {
        const auto& instruction = getInstruction(bus_.read(programCounter_++));

        auto additionalCycle1  = instruction.addrmode();
        auto additionalCcycle2 = instruction.operate();

        currentInstructionCycles_ = instruction.cycles + (additionalCycle1 & additionalCcycle2);
        setStatusRegisterBitValue(CpuFlags::U, true);
    }

    ++clockCount_;
    --currentInstructionCycles_;
}

CpuInstruction& Olc6502::getInstruction(uint8_t operationCode)
{
    if (operationCode < instructions_.size())
        return instructions_[operationCode];

    std::cout << "Error instruction get overflow" << std::endl;
    return defaultInstruction;
}

#define IN(name, addMode, cycles) \
    instructions_.push_back(      \
        {#name, [&]() { return opcodes_.name(); }, [&]() { return addressingModes_.addMode(); }, cycles});

void Olc6502::initInstructionTable()
{
    // clang-format off
    IN(BRK, IMM, 7); IN(ORA, IZX, 6); IN(NNN, IMP, 2); IN(NNN, IMP, 8); IN(NNN, IMP, 3); IN(ORA, ZP0, 3);
    // clang-format on
}
#undef IN

uint8_t Olc6502::getStatusRegisterBitValue(CpuFlags flag)
{
    return ((registers_.status & flag) > 0) ? 1 : 0;
}

void Olc6502::setStatusRegisterBitValue(CpuFlags flag, bool value)
{
    if (value)
        registers_.status |= flag;
    else
        registers_.status &= ~flag;
}

}  // namespace Nes
