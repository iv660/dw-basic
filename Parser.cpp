#include <string>
#include "Parser.h"
#include "ParseHelper.h"

Parser::Parser(std::string code)
{
    this->code = code;
    this->codeIterator = code.begin();
    this->end = code.end();
}

int Parser::pickLineNumber()
{
    std::string number;
    while (ParseHelper::isDigit(*codeIterator) && codeIterator <= end) {
        number.append(1, *codeIterator);
        codeIterator++;
    }
    
    return std::stoi(number);
}

void Parser::skipWhitespace()
{
    while (isspace(*codeIterator) && codeIterator <= end) {
        codeIterator++;
    }
}

std::string Parser::pickRest()
{
    return std::string(codeIterator, end);
}
