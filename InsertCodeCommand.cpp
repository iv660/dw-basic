#include <string>
#include "InsertCodeCommand.h"
#include "Output.h"
#include "Line.cpp"
#include "Parser.h"
#include "ParseHelper.h"

using namespace std;

InsertCodeCommand::InsertCodeCommand(string request, Code *code) 
{
    this->request = request;
    this->code = code;
}

bool InsertCodeCommand::canHandle(string request)
{
    if (ParseHelper::isDigit(request[0])) {
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
    Output out;
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
    Parser parser(request);

    long number = parser.pickLineNumber();
    parser.skipWhitespace();
    string rawCommand = parser.pickRest();

    Line line;
    line.number = number;
    line.rawCommand = rawCommand;

    return line;
}

void InsertCodeCommand::addLine(Line line)
{
    code->addLine(line.number, line.rawCommand);
}
