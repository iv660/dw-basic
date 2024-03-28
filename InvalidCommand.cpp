#include "InvalidCommand.h"
#include "Output.h"

using namespace std;

void InvalidCommand::run()
{
    Output out;
    out.writeLine("Invalid Command");
}

bool InvalidCommand::terminationRequested() 
{
    return false;
}

bool InvalidCommand::canHandle(string request)
{
    return true;
}