#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include <string>
#include "Command.h"

class ExitCommand: public Command
{
    public:
        ExitCommand() {}
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
};

#endif