#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <string>
#include "Output.h"
#include "Command.h"
#include "Code.h"

using namespace std;

class CommandInterpreter 
{
    public:
        CommandInterpreter();
        void run();
    private:
        Code *code;
        Output out;
        void prompt();
        string getLine();
        Command* createCommandByRequest(string request);
};

#endif