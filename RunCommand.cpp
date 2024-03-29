#include <string>
#include "RunCommand.h"
#include "Instruction.h"
#include "CommandMatcher.h"

bool RunCommand::canHandle(string request)
{
    CommandMatcher matcher;
    
    if (matcher.commandIs(request, "run")) {
        return true;
    }
    
    return false;
}

Instruction * RunCommand::createInstructionFrom(string instructionCode)
{
    return nullptr;
}

bool RunCommand::terminationRequested()
{
    return false;
}

void RunCommand::run()
{
    std::map<int, std::string>::iterator codeIterator = code->getLines().begin();
    std::map<int, std::string>::iterator end = code->getLines().end();

    while (codeIterator != end) {
        string instructionCode = codeIterator->second;
        Instruction *instruction = createInstructionFrom(instructionCode);
        instruction->run();
        codeIterator++;
    }
}