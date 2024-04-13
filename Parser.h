#pragma once

#include <string>

class Parser {
    public:
        static bool canParse();
        virtual std::string parse(std::string code) = 0;
};