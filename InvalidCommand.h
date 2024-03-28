#ifndef INVALID_COMMAND_H
#define INVALID_COMMAND_H

#include <string>
#include "Command.h"

class InvalidCommand : public Command
{
    public:
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
};

#endif