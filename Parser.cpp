#include <string>
#include "Parser.h"
#include "ParseHelper.h"

Parser::Parser(std::string code)
{
    this->code = code;
    codeIterator = this->code.begin();
    end = this->code.end();
}

long Parser::pickLineNumber()
{
    std::string lineNumber;
    while (ParseHelper::isDigit(peek()) && !isLast()) {
        lineNumber.push_back(consume());
    }
    
    return std::stol(lineNumber);
}

void Parser::skipWhitespace()
{
    while (isspace(peek()) && !isLast()) {
        codeIterator++;
    }
}

std::string Parser::pickRest()
{
    return std::string(codeIterator, end);
}

void Parser::skipName(std::string name)
{
    codeIterator += name.length();
}

Expression * Parser::pickExpression()
{
    if ('"' == peek()) {
        return pickStringExpression();
    }

    return {};
}

StringExpression * Parser::pickStringExpression()
{
    std::string value = "";

    skip();

    while (!isClosingQuote() && !isLast()) {
        if (isEscapedQuote()) {
            skip();
        }

        value.push_back(consume());
    }

    return new StringExpression(value);
}

char Parser::consume()
{
    return *codeIterator++;
}

char Parser::peek(long depth)
{
    long offset = depth - 1;

    return *(codeIterator + offset);
}

void Parser::skip()
{
    codeIterator++;
}

bool Parser::isClosingQuote()
{
    if (isLast()) {
        return false;
    }

    if (peek() != '"') {
        return false;
    }

    if (peek(2) == '"') {
        return false;
    }

    return true;
}

bool Parser::isEscapedQuote()
{
    if (isLast() || isLast(2)) {
        return false;
    }

    if (peek() == '"' && peek(2) == '"') {
        return true;
    }

    return false;
}

bool Parser::isLast(long depth)
{
    long offset = depth - 1;

    if ((codeIterator + offset) <= end) {
        return false;
    }

    return true;
}
