#pragma once

#include <string>

class StringLiteralParser 
{
    public: 
        static bool canParse(std::string expressionCode);
        std::string parse(std::string expressionCode);
};