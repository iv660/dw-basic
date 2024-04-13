#include "LiteralLevelParser.h"
#include "StringLiteralParser.h"
#include "IntegerLiteralParser.h"

std::string LiteralLevelParser::parse(std::string expressionCode)
{
    if (StringLiteralParser::canParse(expressionCode)) {
        StringLiteralParser parser;

        return parser.parse(expressionCode);
    }

    if (IntegerLiteralParser::canParse(expressionCode)) {
        IntegerLiteralParser parser;

        return parser.parse(expressionCode);
    }

    return {};
}
