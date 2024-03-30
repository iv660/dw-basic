#ifndef INVALID_INSTRUCTION_H
#define INVALID_INSTRUCTION_H

#include <string>
#include "Instruction.h"

class InvalidInstruction : public Instruction
{
    public:
        void run();
        static bool canHandle(std::string request);
        bool terminationRequested();
};

#endif