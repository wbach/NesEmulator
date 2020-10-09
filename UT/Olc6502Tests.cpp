#include <gtest/gtest.h>
#include "Cpu/Olc6502.hpp"
#include "Mocks/BusMock.hpp"
#include <bitset>

using ::testing::Test;

namespace Nes
{
struct Olc6502Wrapper : public Olc6502
{
    Olc6502Wrapper(IBus& bus)
        : Olc6502(bus)
    {
    }

    uint8_t getStatusRegisterBitValue(CpuFlags f)
    {
        return Olc6502::getStatusRegisterBitValue(f);
    }
    void setStatusRegisterBitValue(CpuFlags f , bool v)
    {
        Olc6502::setStatusRegisterBitValue(f, v);
    }
    CpuRegisters getRegisters()
    {
        return registers_;
    }
};

struct Olc6502Should : public ::testing::Test
{
    Olc6502Should()
        : sut_{busMock_}
    {
    }
    BusMock busMock_;
    Olc6502Wrapper sut_;

    void print(const std::string& name, uint8_t value)
    {
        std::cout << name + " = " << std::bitset<8>(value)  << std::endl;
    }
    void print(const std::string& name, uint16_t value)
    {
        std::cout << name + " = " << std::bitset<16>(value)  << std::endl;
    }
};

TEST_F(Olc6502Should, SetClearFlag)
{
    print("status", sut_.getRegisters().status);
    sut_.setStatusRegisterBitValue(CpuFlags::C, true);
    print("status", sut_.getRegisters().status);
    EXPECT_EQ(sut_.getStatusRegisterBitValue(CpuFlags::C), 1);
    sut_.setStatusRegisterBitValue(CpuFlags::C, false);
    EXPECT_EQ(sut_.getStatusRegisterBitValue(CpuFlags::C), 0);
}
}  // namespace Nes
