#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Expression.h"
#include "StringExpression.h"

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
        StringExpression * pickStringExpression();
        char consume();
        char peek(long depth = 1);
        void skip();
        bool isLast(long depth = 1);
        bool isClosingQuote();
        bool isEscapedQuote();
};

#endif