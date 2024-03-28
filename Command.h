#ifndef COMMAND_H
#define COMMAND_H

#include <string>

using namespace std;

class Command 
{
    public:
        Command() {}
        virtual void run() = 0;
        virtual bool terminationRequested() = 0;
        static bool canHandle(string request);
};

#endif