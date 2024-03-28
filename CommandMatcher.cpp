#include <cstring>
#include <string>
#include "CommandMatcher.h"

bool CommandMatcher::commandIs(string rawCommand, string compareTo)
{
    string commandStart = rawCommand.substr(0, compareTo.length());
    
    if (stricmp(commandStart.c_str(), compareTo.c_str()) == 0) {
        return true;
    }

    return false;
}