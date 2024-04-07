#include "StringLiteralExpression.h"

StringLiteralExpression::StringLiteralExpression(std::string value)
{
    this->value = std::move(value);
}

std::string StringLiteralExpression::toString()
{
    return value;
}
