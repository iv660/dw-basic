#include <string>
#include <iostream>
#include "CommandInterpreter.h"
#include "Command.h"
#include "ExitCommand.cpp"
#include "InvalidCommand.cpp"
#include "RunCommand.cpp"
#include "InsertCodeCommand.cpp"
#include "Code.cpp"
#include "ListCommand.cpp"

using namespace std;

CommandInterpreter::CommandInterpreter() 
{
    code = new Code;
}

void CommandInterpreter::run()
{
    bool shouldEnd = false;
    
    do {
        prompt();
        string request = getLine();
        Command *command = createCommandByRequest(request);
        command->run();
        shouldEnd = command->terminationRequested();
        
        delete command;
    } while (!shouldEnd);
}

void CommandInterpreter::prompt()
{
    out.writeLine("Ok");
}

string CommandInterpreter::getLine()
{
    string line;
    getline(cin, line);
    
    return line;
}


Command* CommandInterpreter::createCommandByRequest(string request)
{
    if (InsertCodeCommand::canHandle(request)) {
        return new InsertCodeCommand(request, code);
    }
    if (ListCommand::canHandle(request)) {
        return new ListCommand(code);
    }
    if (RunCommand::canHandle(request)) {
        return new RunCommand;
    }
    if (ExitCommand::canHandle(request)) {
        return new ExitCommand;
    }

    return new InvalidCommand;
}

