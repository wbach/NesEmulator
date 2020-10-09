#include <iostream>
#include "NesEmulator.hpp"

int main(int, char**)
{
    Nes::NesEmulator emulator;
    emulator.run("game.rom");
    return 0;
}
