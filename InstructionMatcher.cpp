#include <string>
#include <cstring>
#include "InstructionMatcher.h"

bool InstructionMatcher::instructionIs(string instructionCode, string compareTo)
{
    string instructionName = instructionCode.substr(0, compareTo.length());
    
    if (stricmp(instructionName.c_str(), compareTo.c_str()) == 0) {
        return true;
    }

    return false;
}