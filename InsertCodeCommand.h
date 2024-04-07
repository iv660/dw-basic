#ifndef INSERT_CODE_COMMAND_H
#define INSERT_CODE_COMMAND_H

#include <string>
#include "Command.h"
#include "Line.h"
#include "Code.h"

using namespace std;

class InsertCodeCommand : public Command
{
    public:
        InsertCodeCommand(string request, Code *code);
        void run();
        bool terminationRequested();
        static bool canHandle(string request);
    private:
        static bool isDigit(char character);
        Line parse(string request);
        string request;
        Code * code;
        void addLine(Line line);
        long pickLineNumberFrom(string::iterator &requestIterator, string::iterator end);
        void skipWhitespaceIn(string::iterator &requestIterator, string::iterator end);
        string pickRawCommandFrom(string::iterator &requestIterator, string::iterator end);
};


#endif