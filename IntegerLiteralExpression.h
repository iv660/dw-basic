#pragma once

#include <string>
#include "Expression.h"

class IntegerLiteralExpression: public Expression
{
    public:
        IntegerLiteralExpression(long value);
        std::string toString();
    private:
        long value;
};