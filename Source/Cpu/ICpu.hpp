#pragma once
#include <string>

namespace Nes
{
class ICpu
{
public:
    ~ICpu() = default;

    virtual void reset()                       = 0;
    virtual void interruptRequest()            = 0;
    virtual void nonMaskableInterruptRequest() = 0;
    virtual void clock()                       = 0;
};
}  // namespace Nes
