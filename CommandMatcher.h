#ifndef COMMAND_MATCHER_H
#define COMMAND_MATCHER_H

#include <string>

using namespace std;

class CommandMatcher
{
    public:
        bool commandIs(string rawCommand, string compareTo);
};

#endif