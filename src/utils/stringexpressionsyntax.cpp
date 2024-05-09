#include "../../headers/utils/stringexpressionsyntax.h"

StringExpressionSyntax::StringExpressionSyntax(SyntaxToken *stringToken)
    : StringExpressionSyntax(stringToken, stringToken->getValue()) {}

StringExpressionSyntax::StringExpressionSyntax(SyntaxToken *stringToken, Value value)
    : mStringToken(stringToken)
    , mValue(value) {}

SyntaxKind StringExpressionSyntax::getKind() {
    return StringExpression;
}

vector<SyntaxNode *> StringExpressionSyntax::getChildren() {
    return { mStringToken };
}

SyntaxToken *StringExpressionSyntax::getStringToken() {
    return mStringToken;
}

Value StringExpressionSyntax::getValue() {
    return mValue;
}
