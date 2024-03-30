#include <string>
#include <vector>
#include "Code.h"
#include "Line.h"
#include "Output.h"

using namespace std;

Code* Code::addLine(int number, string rawCommand)
{
    lines[number] = rawCommand;

    return this;
}

map<int, string> Code::getLines()
{
    return lines;
}
