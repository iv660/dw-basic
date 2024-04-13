#include <string>
#include "RawExpression.h"
#include "IntegerLiteralExpression.h"
#include "StringLiteralExpression.h"
#include "Expression.h"
#include "LiteralLevelParser.h"

RawExpression::RawExpression(std::string expressionCode): expressionCode(expressionCode) {}

std::string RawExpression::toString()
{
    std::string result(expressionCode);
    LiteralLevelParser levelParser;

    result = levelParser.parse(result);

    return result;
}
