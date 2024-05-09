#include "../../headers/utils/nameexpressionsyntax.h"

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken *nameToken, Value value)
    : mIdenrifierToken(nameToken)
    , mValue(value) {}

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken *nameToken)
    : NameExpressionSyntax(nameToken, nameToken->getValue()) {}

SyntaxKind NameExpressionSyntax::getKind() {
    return NameExpression;
}

vector<SyntaxNode *> NameExpressionSyntax::getChildren() {
    return { mIdenrifierToken };
}

SyntaxToken *NameExpressionSyntax::getIdentifierToken() {
    return mIdenrifierToken;
}

Value NameExpressionSyntax::getValue() {
    return mValue;
}
