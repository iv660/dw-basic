#include "IntegerLiteralExpression.h"

IntegerLiteralExpression::IntegerLiteralExpression(long value)
{
    this->value = value;
}

std::string IntegerLiteralExpression::toString()
{
    return std::to_string(value);
}
