#include <string>
#include "RunCommand.h"
#include "Instruction.h"
#include "CommandMatcher.h"
#include "RemInstruction.cpp"
#include "InvalidInstruction.cpp"
#include "Output.h"

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
    if (RemInstruction::canHandle(instructionCode)) {
        return new RemInstruction;
    }
    return new InvalidInstruction();
}

bool RunCommand::terminationRequested()
{
    return false;
}

RunCommand::RunCommand(Code * code)
{
    this->code = code;
}

void RunCommand::run()
{
    std::map<int, std::string> lines = code->getLines();
    std::map<int, std::string>::iterator codeIterator = lines.begin();
    std::map<int, std::string>::iterator end = lines.end();

    bool isTerminated = false;
    int haltInLine = 0;
    while (codeIterator != end && !isTerminated) {
        string instructionCode = codeIterator->second;
        Instruction *instruction = createInstructionFrom(instructionCode);
        
        instruction->run();
        
        isTerminated = instruction->terminationRequested();
        delete instruction;
        
        if (isTerminated) {
            break;
        }
        
        codeIterator++; 
    }

    if (isTerminated) {
        Output out;
        out.writeString("Halt in line " + std::to_string(codeIterator->first));
    }
}