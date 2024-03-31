#include "ParseHelper.h"

bool ParseHelper::isDigit(char character)
{
    if (character < '0') {
        return false;
    }
    
    if (character > '9') {
        return false;
    }
    
    return true;
}