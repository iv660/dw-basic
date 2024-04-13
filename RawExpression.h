#pragma once

#include <string>
#include "Expression.h"

class RawExpression: public Expression
{
    public:
        RawExpression(std::string expressionCode);
        std::string toString();
    private:
        std::string expressionCode;
};