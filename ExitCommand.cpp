#include <string>
#include "ExitCommand.h"
#include "CommandMatcher.h"

using namespace std;

void ExitCommand::run()
{
    
}

bool ExitCommand::terminationRequested()
{
    return true;
}

bool ExitCommand::canHandle(string command)
{
    CommandMatcher matcher;

    if (matcher.commandIs(command, "exit")) {
        return true;
    }
    
    return false;
}