#include "../../headers/utils/nameexpressionsyntax.h"

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken *nameToken, void *value) 
    : mIdenrifierToken(nameToken)
    , mValue(value) {}

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken *nameToken) 
    : NameExpressionSyntax(nameToken, nameToken->getValue()) {}

SyntaxKind NameExpressionSyntax::getKind() {
    return NameExpression;
}

vector<SyntaxNode *> NameExpressionSyntax::getChildren() {
    return vector<SyntaxNode *>({ mIdenrifierToken });
}

SyntaxToken *NameExpressionSyntax::getIdentifierToken() {
    return mIdenrifierToken;
}

void *NameExpressionSyntax::getValue() {
    return mValue;
}

