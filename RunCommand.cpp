#include <string>
#include "RunCommand.h"
#include "Output.h"

bool RunCommand::canHandle(string request)
{
    if ("run" == request) {
        return true;
    }
    
    return false;
}

bool RunCommand::terminationRequested()
{
    return false;
}

void RunCommand::run()
{
    Output out;
    out.writeLine("Running...");
}