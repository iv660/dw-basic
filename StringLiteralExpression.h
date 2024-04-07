#pragma once

#include <string>
#include "Expression.h"

class StringLiteralExpression: public Expression
{
    public:
        StringLiteralExpression(std::string value);
        std::string toString();
    private:
        std::string value;
};