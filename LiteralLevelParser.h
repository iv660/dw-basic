#pragma once

#include <string>
#include "Parser.h"

class LiteralLevelParser: public Parser
{
    public:
        std::string parse(std::string expressionCode);
};