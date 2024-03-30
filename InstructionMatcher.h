#ifndef INSTRUCTION_MATCHER_H
#define INSTRUCTION_MATCHER_H

#include <string>

using namespace std;

class InstructionMatcher
{
    public:
        bool instructionIs(string instructionCode, string compareTo);
};

#endif