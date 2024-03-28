#ifndef RUN_COMMAND_H
#define RUN_COMMAND_H

#include <string>
#include "Command.h"

using namespace std;

class RunCommand : public Command
{
    public:
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
};


#endif