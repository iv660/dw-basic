#include <iostream>
#include "Output.h"

void Output::writeLine(const char* text) 
{
    std::cout << text << std::endl;
} 

void Output::writeString(string text) 
{
    std::cout << text << std::endl;
} 
