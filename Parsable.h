#pragma once

#include <string>
#include "Expression.h"
#include "StringLiteralExpression.h"
#include "IntegerLiteralExpression.h"

class Parsable
{
    public:
        Parsable(std::string code);
        long pickLineNumber();
        long pickInteger();
        std::string pickString();
        void skipWhitespace();
        void skipName(std::string name);
        void skipNextToken();
        Expression *pickExpression();
        std::string pickRest();
        bool isLast(long depth = 1);
        std::string consumeNextToken();
        std::string consumeWhitespace();
        std::string peekNextToken(int depth = 1);
    private:
        std::string code;
        std::string::iterator codeIterator;
        std::string::iterator end;
        StringLiteralExpression *pickStringLiteralExpression();
        IntegerLiteralExpression *pickIntegerLiteralExpression();
        char consume();
        char peek(long depth = 1);
        void skip();
        bool isClosingQuote();
        bool isEscapedQuote();
        bool isDigit();
};

