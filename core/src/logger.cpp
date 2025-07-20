#include "logger.h"

Logger::Logger()
{
    // Startup tasks of the Logger when the Engine starts:
}

void Logger::log(std::string statement)
{
    // this function will wrap the statement with date/time and also write the statement to a log<date>.txt file

    if (!isActive)
    {
        return;
    }

    std::cout << statement << std::endl; // simply printing for now
}

void Logger::log(int number)
{
    // this function will wrap the statement with date/time and also write the statement to a log<date>.txt file

    if (!isActive)
    {
        return;
    }

    std::cout << number << std::endl; // simply printing for now
}

// Define the global instance of Logger, this will be included using the extern keyword in all other files that require it
Logger logger;