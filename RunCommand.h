#ifndef RUN_COMMAND_H
#define RUN_COMMAND_H

#include <string>
#include "Command.h"
#include "Code.h"
#include "Instruction.h"
#include "Line.h"

using namespace std;

class RunCommand : public Command
{
    public:
        RunCommand(Code *code);
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
    private:
        Code *code;
        Instruction * createInstructionFrom(string instructionCode);
};


#endif