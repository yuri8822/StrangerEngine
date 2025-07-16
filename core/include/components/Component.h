#pragma once

#include <iostream>

struct Component
{
    virtual std::string Identifier() = 0;
};