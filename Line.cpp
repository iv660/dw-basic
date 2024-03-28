#include "Line.h"

string Line::toString()
{
    return std::to_string(number) + " " + rawCommand;
}