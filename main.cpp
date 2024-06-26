#define DW_BASIC_VERSION "0.0.1.alpha"

#include "include.cpp"
#include "Output.cpp"
#include "CommandInterpreter.cpp"
#include "InstructionMatcher.cpp"

int main()
{
    Output out;
    out.writeLine("DW BASIC 2024 v" DW_BASIC_VERSION);
    
    CommandInterpreter interpreter;
    interpreter.run();
    
    return 0;
}
