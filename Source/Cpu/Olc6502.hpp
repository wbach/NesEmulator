#include "AddressingModes.hpp"
#include "CpuFlags.hpp"
#include "CpuInstruction.hpp"
#include "CpuRegisters.hpp"
#include "ICpu.hpp"
#include "Opcodes.hpp"

namespace Nes
{
class IBus;
class Olc6502 : public ICpu
{
public:
    Olc6502(IBus&);

    void reset() override;
    void interruptRequest() override;
    void nonMaskableInterruptRequest() override;
    void clock() override;

protected:
    void initInstructionTable();
    uint8_t getStatusRegisterBitValue(CpuFlags);
    void setStatusRegisterBitValue(CpuFlags, bool);
    CpuInstruction& getInstruction(uint8_t);

protected:
    IBus& bus_;
    AddressingModes addressingModes_;
    Opcodes opcodes_;
    std::vector<CpuInstruction> instructions_;

    CpuRegisters registers_;
    uint16_t programCounter_ = 0x0000;

    uint8_t currentInstructionCycles_ = 0;
    uint64_t clockCount_              = 0;
};
}  // namespace Nes
