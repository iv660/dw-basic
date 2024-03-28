/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#define DW_BASIC_VERSION "0.0.1"

#include "Output.h"
#include "CommandInterpreter.h"

int main()
{
    Output out;
    out.writeLine("DW BASIC 2024 v" DW_BASIC_VERSION);
    
    CommandInterpreter interpreter;
    interpreter.run();
    
    return 0;
}
