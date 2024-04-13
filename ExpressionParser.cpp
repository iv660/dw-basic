#include <string>
#include "ExpressionParser.h"
#include "LiteralLevelParser.h"

std::string ExpressionParser::parse(std::string code)
{
    std::string result(code);
    LiteralLevelParser literalLevel;

    result = literalLevel.parse(result);

    return result;
}