#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <string>
#include "Output.h"
#include "Command.h"

using namespace std;

class CommandInterpreter 
{
    public:
        void run();
    private:
        Output out;
        void prompt();
        string getLine();
        Command* createCommandByRequest(string request);
};

#endif