#pragma once

#include "core.h"
extern Core core;

class Runtime
{
private:

public:
    Runtime();
    void Update(bool &);
    void Run();
};