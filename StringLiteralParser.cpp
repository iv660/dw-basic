#include "StringLiteralParser.h"
#include "Parsable.h"

bool StringLiteralParser::canParse(std::string expressionCode)
{
    return expressionCode[0] == '\"';
}

std::string StringLiteralParser::parse(std::string expressionCode)
{
    Parsable parsable(expressionCode);

    return parsable.pickString();
}
