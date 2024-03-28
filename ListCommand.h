#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include <string>
#include "Command.h"
#include "Code.h"
#include "Output.h"

class ListCommand: public Command
{
    public:
        ListCommand(Code *code);
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
    private:
        Code *code;
        Output *out;
};

#endif