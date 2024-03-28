#ifndef CODE_H
#define CODE_H

#include <string>
#include <map>
#include "Line.h"

using namespace std;

class Code 
{
    public: 
        Code* addLine(int number, string rawCommand);
    private:
        // Line *lines;
        map<int, string> lines;
        // int linesCount = 0;
};

#endif