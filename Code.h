#ifndef CODE_H
#define CODE_H

#include <string>
#include <map>
#include "Line.h"

using namespace std;

class Code 
{
    public: 
        Code* addLine(long number, string rawCommand);
        map<long, string> getLines();
        void clear();
    private:
        map<long, string> lines;
};

#endif