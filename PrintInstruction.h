#ifndef PRINT_INSTRUCTION_H
#define PRINT_INSTRUCTION_H

#include <string>
#include "Instruction.h"

class PrintInstruction : public Instruction
{
    public:
        PrintInstruction(std::string instructionCode);
        static bool canHandle(std::string instructionCode);
        void run();
        bool terminationRequested();
    private:
        std::string instructionCode;
        static const std::string INSTRUCTION_NAME;
        void output(std::string value);
};

#endif
