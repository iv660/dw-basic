#include <string>
#include <vector>
#include "Code.h"
#include "Line.h"
#include "Output.h"

using namespace std;

Code* Code::addLine(long number, string rawCommand)
{
    lines[number] = rawCommand;

    return this;
}

map<long, string> Code::getLines()
{
    return lines;
}
