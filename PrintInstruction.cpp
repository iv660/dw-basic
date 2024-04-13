#include "PrintInstruction.h"
#include "InstructionMatcher.h"
#include "Parsable.h"
#include "Expression.h"
#include "Output.h"
#include "ExpressionParser.h"

const std::string PrintInstruction::INSTRUCTION_NAME = "print";

PrintInstruction::PrintInstruction(std::string instructionCode)
{
    this->instructionCode = instructionCode;
}

bool PrintInstruction::canHandle(std::string instructionCode)
{
    InstructionMatcher matcher;

    if (matcher.instructionIs(instructionCode, PrintInstruction::INSTRUCTION_NAME)) {
        return true;
    }

    return false;
}

void PrintInstruction::run () 
{
    Parsable parser(instructionCode);

    parser.skipName(PrintInstruction::INSTRUCTION_NAME);
    parser.skipWhitespace();
    
    ExpressionParser expressionParser;
    output(expressionParser.parse(parser.pickRest()));
}

bool PrintInstruction::terminationRequested()
{
    return false;
}

void PrintInstruction::output(std::string value)
{
    Output out;
    out.writeString(value);
}
