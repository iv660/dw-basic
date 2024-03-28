#ifndef INSERT_CODE_COMMAND_H
#define INSERT_CODE_COMMAND_H

#include <string>
#include "Command.h"

using namespace std;

class InsertCodeCommand : public Command
{
    public:
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
    private:
        static bool isDigit(char character);
};


#endif