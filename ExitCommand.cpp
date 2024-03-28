#include <string>
#include "ExitCommand.h"

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
    if ("exit" == command) {
        return true;
    }
    
    return false;
}