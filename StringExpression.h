#pragma once

#include <string>
#include "Expression.h"

class StringExpression: public Expression
{
    public:
        StringExpression(std::string value);
        std::string toString();
    private:
        std::string value;
};