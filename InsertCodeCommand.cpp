#include <string>
#include "InsertCodeCommand.h"
#include "Output.h"

bool InsertCodeCommand::canHandle(string request)
{
    if (InsertCodeCommand::isDigit(request[0])) {
        return true;
    }
    
    return false;
}

bool InsertCodeCommand::terminationRequested()
{
    return false;
}

void InsertCodeCommand::run()
{
    Output out;
    out.writeLine("Inserting...");
}

bool InsertCodeCommand::isDigit(char character)
{
    if (character < '0') {
        return false;
    }
    
    if (character > '9') {
        return false;
    }
    
    return true;
}
