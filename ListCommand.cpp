#include <string>
#include "ListCommand.h"
#include "Output.h"


ListCommand::ListCommand(Code * code)
{
    this->code = code;
    out = new Output;
}

void ListCommand::run()
{
    map<int, string>::iterator linesIterator;
    for (auto const& [number, rawCode] : this->code->getLines()) {
        out->writeString(std::to_string(number) + " " + rawCode);
    }
}

bool ListCommand::terminationRequested()
{
    return false;
}

bool ListCommand::canHandle(string request)
{
    if ("list" == request) {
        return true;
    }

    return false;
}
