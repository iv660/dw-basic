#ifndef LINE_H
#define LINE_H

#include <string>

using namespace std;

class Line 
{
    public: 
        int number;
        string rawCommand;
        string toString();
};

#endif