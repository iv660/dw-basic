#pragma once

#include <string>
#include "Command.h"
#include "Code.h"

class NewCommand: public Command
{
    public:
        NewCommand(Code *code);
        static bool canHandle(std::string request);
        bool terminationRequested();
        void run();
    private:
        Code *code;
};