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
        map<int, string> getLines();
    private:
        map<int, string> lines;
};

#endif