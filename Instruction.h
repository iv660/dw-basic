#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction
{
    public:
        virtual void run() = 0;
        virtual bool terminationRequested() = 0;
};

#endif
