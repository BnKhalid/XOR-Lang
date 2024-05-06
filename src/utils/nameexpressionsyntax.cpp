#include "../../headers/utils/nameexpressionsyntax.h"

NameExpressionSyntax::NameExpressionSyntax(SyntaxToken *nameToken) 
    : mIdenrifierToken(nameToken) {}

SyntaxKind NameExpressionSyntax::getKind() {
    return NameExpression;
}

vector<SyntaxNode *> NameExpressionSyntax::getChildren() {
    return vector<SyntaxNode *>({ mIdenrifierToken });
}

SyntaxToken *NameExpressionSyntax::getIdentifierToken() {
    return mIdenrifierToken;
}

