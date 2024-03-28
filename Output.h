#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

using namespace std;

class Output
{
    public:
        void writeLine(const char* text);
        void writeString(string text);
};

#endif