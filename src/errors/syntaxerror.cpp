#include "../../headers/errors/syntaxerror.h"

SyntaxError::SyntaxError(SyntaxKind expected, SyntaxKind found)
    : mExpected(expected)
    , mFound(found) {}

SyntaxKind SyntaxError::getExpected() {
    return mExpected;
}

string SyntaxError::getMessage() {
    return "Syntax error\nExpected: \""
        + Utilities::parseSyntaxKind(mExpected) +
        "\" but found: \""
        + Utilities::parseSyntaxKind(mFound) + "\"\n";
}
