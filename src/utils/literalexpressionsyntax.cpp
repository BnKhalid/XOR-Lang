#include "../../headers/utils/literalexpressionsyntax.h"

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken *numberToken)
    : mNumberToken(numberToken) {}

SyntaxKind LiteralExpressionSyntax::getKind() {
    return LiteralExpressionToken;
}

vector<SyntaxNode *> LiteralExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mNumberToken);
    return children;
}

SyntaxToken *LiteralExpressionSyntax::getNumberToken() {
    return mNumberToken;
}
