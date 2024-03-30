#include "RemInstruction.h"
#include "InstructionMatcher.h"

void RemInstruction::run()
{
    // Do nothing
}

bool RemInstruction::terminationRequested()
{
    return false;
}

bool RemInstruction::canHandle(std::string instructionCode)
{
    InstructionMatcher matcher;

    if (matcher.instructionIs(instructionCode, "rem")) {
        return true;
    }

    return false;
}