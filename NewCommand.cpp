#include <string>
#include "NewCommand.h"
#include "CommandMatcher.h"

NewCommand::NewCommand(Code *code)
{
    this->code = code;
}

bool NewCommand::canHandle(std::string request)
{
    CommandMatcher matcher;

    if (matcher.commandIs(request, "new")) {
        return true;
    }

    return false;
}

bool NewCommand::terminationRequested()
{
    return false;
}

void NewCommand::run()
{
    code->clear();
}
