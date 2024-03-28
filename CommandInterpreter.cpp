#include <string>
#include <iostream>
#include "CommandInterpreter.h"
#include "Command.h"
#include "ExitCommand.h"
#include "InvalidCommand.h"
#include "RunCommand.h"
#include "InsertCodeCommand.h"

using namespace std;

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
        return new InsertCodeCommand();
    }
    if (RunCommand::canHandle(request)) {
        return new RunCommand();
    }
    if (ExitCommand::canHandle(request)) {
        return new ExitCommand();
    } else {
        return new InvalidCommand();
    }
}