#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser
{
    public:
        Parser(std::string code);
        int pickLineNumber();
        void skipWhitespace();
        std::string pickRest();
    private:
        std::string code;
        std::string::iterator codeIterator;
        std::string::iterator end;
};

#endif