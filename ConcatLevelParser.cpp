#include "ConcatLevelParser.h"
#include "Parsable.h"
#include "StringLiteralToken.h"
#include "IntegerLiteralToken.h"
#include "ConcatenationToken.h"

std::string ConcatLevelParser::parse(std::string code)
{
    std::string result;
    Parsable parsable(code);

    while (!parsable.isLast()) {
        if (matchesLevelPattern(parsable)) {
            std::string evaluationResult;

            evaluationResult += evaluateNextExpressionFrom(parsable);

            while (matchesExpressionTail(parsable)) {
                evaluationResult += 
                    evaluateExpressionTailFrom(evaluationResult, parsable);
            }

            result += makeStringLiteralOf(evaluationResult);
        }
        
        result += parsable.consumeNextToken() + parsable.consumeWhitespace();
    }

    return result;
}

bool ConcatLevelParser::matchesLevelPattern(Parsable parsable)
{
    if (!StringLiteralToken::matches(parsable.peekNextToken(1)) 
        && ! IntegerLiteralToken::matches(parsable.peekNextToken(1)))
    {
        return false;
    }

    if (ConcatenationToken::matches(parsable.peekNextToken(2)!) {
        return false;
    }

std::string ConcatLevelParser::evaluateNextExpressionFrom(Parsable parsable)
{
    std::string leftHandToken = parsable.consumeNextToken();
    parsable.skipNextToken();
    std::string rightHandToken = parsable.consumeNextToken();
    
    return evaluateExpression(leftHandToken, rightHandToken);
}

std::string ConcatLevelParser::evaluateExpressionTailFrom(std::string resultSoFar, Parsable parsable)
{
    std::string leftHandToken = makeStringLiteralOf(resultSoFar);
    parsable.skipNextToken();
    std::string rightHandToken = parsable.consumeNextToken();

    return evaluateExpression(leftHandToken, rightHandToken);
}

    if (!StringLiteralToken::matches(parsable.peekNextToken(3)) 
        && ! IntegerLiteralToken::matches(parsable.peekNextToken(3)))
    {
        return false;
    }

    return true;
}
