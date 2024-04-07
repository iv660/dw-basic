#pragma once

#include <string>
#include "Expression.h"
#include "StringLiteralExpression.h"
#include "IntegerLiteralExpression.h"

class Parser
{
    public:
        Parser(std::string code);
        long pickLineNumber();
        void skipWhitespace();
        void skipName(std::string name);
        Expression * pickExpression();
        std::string pickRest();
    private:
        std::string code;
        std::string::iterator codeIterator;
        std::string::iterator end;
        StringLiteralExpression * pickStringLiteralExpression();
        IntegerLiteralExpression * pickIntegerLiteralExpression();
        char consume();
        char peek(long depth = 1);
        void skip();
        bool isLast(long depth = 1);
        bool isClosingQuote();
        bool isEscapedQuote();
        bool isDigit();
};

