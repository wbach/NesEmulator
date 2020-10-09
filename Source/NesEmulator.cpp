#include "NesEmulator.hpp"
#include "Bus/Bus.hpp"
#include "Cpu/Olc6502.hpp"
#include <iostream>

namespace Nes
{
NesEmulator::NesEmulator()
    : bus_{std::make_unique<Bus>()}
    , cpu_{std::make_unique<Olc6502>(*bus_)}
{
    std::cout << "Nes emulator" << std::endl;
}

NesEmulator::~NesEmulator()
{

}

void NesEmulator::run(const std::string& file)
{
    std::cout << "starting " + file + "..." << std::endl;
}
}  // namespace Nes
