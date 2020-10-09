#pragma once
#include <memory>
#include <string>

namespace Nes
{
class ICpu;
class IBus;

class NesEmulator
{
public:
    NesEmulator();
    ~NesEmulator();
    void run(const std::string&);

private:
    std::unique_ptr<IBus> bus_;
    std::unique_ptr<ICpu> cpu_;
};
}  // namespace Nes
