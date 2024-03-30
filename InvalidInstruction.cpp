#include "InvalidInstruction.h"
#include "Output.h"

void InvalidInstruction::run()
{
    Output out;
    out.writeLine("Invalid Instruction");
}

bool InvalidInstruction::canHandle(string request)
{
    return true;
}

bool InvalidInstruction::terminationRequested()
{
    return true;
}