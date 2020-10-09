#include "Bus.hpp"
#include <iostream>

namespace Nes
{
Bus::Bus()
{
    for (auto& cell : ram_)
        cell = 0x00;
}

void Bus::write(Address address, Data data)
{
    if (address >= ram_.size())
    {
        ram_[address] = data;
    }
    else
    {
        std::cout << "Bus writing error, invalid address." << std::endl;
    }
}
uint8_t Bus::read(Address address)
{
    if (address >= ram_.size())
    {
        return ram_[address];
    }

    std::cout << "Bus reading error, invalid address." << std::endl;
    return 0x00;
}
}  // namespace Nes
