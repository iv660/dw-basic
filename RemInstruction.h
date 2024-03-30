#ifndef REM_INSTRUCTION_H
#define REM_INSTRUCTION_H

#include <string>
#include "Instruction.h"

class RemInstruction : public Instruction
{
    public:
        void run();
        bool terminationRequested();
        static bool canHandle(std::string instructionCode);
};

#endif