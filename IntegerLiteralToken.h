#pragma once

#include "Parsable.h"

class IntegerLiteralToken
{
    public:
        static bool matches(Parsable parsable);
};