#include <string>
#include "Parsable.h"
#include "ParseHelper.h"

Parsable::Parsable(std::string code)
{
    this->code = code;
    codeIterator = this->code.begin();
    end = this->code.end();
}

long Parsable::pickLineNumber()
{
    return pickInteger();
}

long Parsable::pickInteger()
{
    std::string valueString;
    while (ParseHelper::isDigit(peek()) && !isLast()) {
        valueString.push_back(consume());
    }
    
    return std::stol(valueString);
}

void Parsable::skipWhitespace()
{
    while (isspace(peek()) && !isLast()) {
        codeIterator++;
    }
}

std::string Parsable::pickRest()
{
    return std::string(codeIterator, end);
}

void Parsable::skipName(std::string name)
{
    codeIterator += name.length();
}

Expression * Parsable::pickExpression()
{
    if ('"' == peek()) {
        return pickStringLiteralExpression();
    }

    if (isDigit()) {
        return pickIntegerLiteralExpression();
    }

    return {};
}

StringLiteralExpression * Parsable::pickStringLiteralExpression()
{
    std::string value = "";

    skip();

    while (!isClosingQuote() && !isLast()) {
        if (isEscapedQuote()) {
            skip();
        }

        value.push_back(consume());
    }

    return new StringLiteralExpression(value);
}

IntegerLiteralExpression * Parsable::pickIntegerLiteralExpression()
{
    std::string valueString = "";

    while (isDigit()) {
        valueString.push_back(consume());
    }

    long value = std::stol(valueString);

    return new IntegerLiteralExpression(value);
}

char Parsable::consume()
{
    return *codeIterator++;
}

char Parsable::peek(long depth)
{
    long offset = depth - 1;

    return *(codeIterator + offset);
}

void Parsable::skip()
{
    codeIterator++;
}

bool Parsable::isClosingQuote()
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

bool Parsable::isEscapedQuote()
{
    if (isLast() || isLast(2)) {
        return false;
    }

    if (peek() == '"' && peek(2) == '"') {
        return true;
    }

    return false;
}

bool Parsable::isDigit()
{
    if (isLast()) {
        return false;
    }

    if (ParseHelper::isDigit(peek())) {
        return true;
    }

    return false;
}

bool Parsable::isLast(long depth)
{
    long offset = depth - 1;

    if ((codeIterator + offset) <= end) {
        return false;
    }

    return true;
}
