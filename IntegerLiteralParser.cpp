#include <string>
#include "IntegerLiteralParser.h"
#include "Parsable.h"
#include "ParseHelper.h"

bool IntegerLiteralParser::canParse(std::string expressionCode)
{
    if (ParseHelper::isDigit(expressionCode[0])) {
        return true;
    }

    return false;
}

std::string IntegerLiteralParser::parse(std::string expressionCode)
{
    Parsable parsable(expressionCode);
    
    return std::to_string(parsable.pickInteger());
}
