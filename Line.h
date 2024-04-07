#ifndef LINE_H
#define LINE_H

#include <string>

using namespace std;

class Line 
{
    public: 
        long number;
        string rawCommand;
        string toString();
};

#endif