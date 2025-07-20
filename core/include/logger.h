#pragma once

#include <iostream>

// The logger is completely isolated from the rest of the engine and is not a module of it. think of it more like a simple utility to easily manage
// when i want my console logs to be printed or not.

class Logger
{
public:
    bool isActive = false;
    
    Logger();
    void log(std::string);
    void log(int);
};