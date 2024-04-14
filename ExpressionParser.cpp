#include <string>
#include "ExpressionParser.h"
#include "LiteralLevelParser.h"
#include "ConcatLevelParser.h"

std::string ExpressionParser::parse(std::string code)
{
    std::string result(code);
    LiteralLevelParser literalLevel;
    ConcatLevelParser concatLevel;

    result = concatLevel.parse(result);
    result = literalLevel.parse(result);

    return result;
}