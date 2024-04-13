#pragma once

#include <string>

class IntegerLiteralParser
{
    public:
        static bool canParse(std::string expressionCode);
        std::string parse(std::string expressionCode);
};