#include "StringExpression.h"

StringExpression::StringExpression(std::string value)
{
    this->value = std::move(value);
}

std::string StringExpression::toString()
{
    return value;
}
