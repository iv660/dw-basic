#include <string>
#include "InsertCodeCommand.h"
#include "Output.h"
#include "Line.h"

using namespace std;

InsertCodeCommand::InsertCodeCommand(string request, Code *code) 
{
    this->request = request;
    this->code = code;
}

bool InsertCodeCommand::canHandle(string request)
{
    if (InsertCodeCommand::isDigit(request[0])) {
        return true;
    }
    
    return false;
}

bool InsertCodeCommand::terminationRequested()
{
    return false;
}

void InsertCodeCommand::run()
{
    Line line = parse(request);
    addLine(line);
}

bool InsertCodeCommand::isDigit(char character)
{
    if (character < '0') {
        return false;
    }
    
    if (character > '9') {
        return false;
    }
    
    return true;
}

Line InsertCodeCommand::parse(string request)
{
    string::iterator requestIterator = request.begin();
    
    int number = pickLineNumberFrom(requestIterator, request.end());
    skipWhitespaceIn(requestIterator, request.end());
    string rawCommand = pickRawCommandFrom(requestIterator, request.end());// string(requestIterator, request.end());

    Line line;
    line.number = number;
    line.rawCommand = rawCommand;

    return line;
}

int InsertCodeCommand::pickLineNumberFrom(string::iterator &requestIterator, string::iterator end)
{
    string number;
    while (isDigit(*requestIterator) && requestIterator <= end) {
        number.append(1, *requestIterator);
        requestIterator++;
    }
    
    return std::stoi(number);
}

void InsertCodeCommand::skipWhitespaceIn(string::iterator &requestIterator, string::iterator end)
{
    while (isspace(*requestIterator) && requestIterator <= end) {
        requestIterator++;
    }
}

string InsertCodeCommand::pickRawCommandFrom(string::iterator &requestIterator, string::iterator end)
{
    return string(requestIterator, end);
}

void InsertCodeCommand::addLine(Line line)
{
    code->addLine(line.number, line.rawCommand);
}
