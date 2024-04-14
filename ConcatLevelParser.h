#pragma once

#include <string>
#include "Parsable.h"

class ConcatLevelParser 
{
    public:
        std::string parse(std::string code);
    private:
        bool matchesLevelPattern(Parsable parsable);
        bool matchesExpressionTail(Parsable parsable);
        std::string evaluateExpression(std::string leftHandToken, std::string rightHandToken);
        std::string makeStringLiteralOf(std::string value);
        std::string evaluateNextExpressionFrom(Parsable parsable);
        std::string evaluateExpressionTailFrom(std::string resultSoFar, Parsable parsable);
};