#include "../../headers/utils/literalexpressionsyntax.h"

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken *numberToken, void *value)
    : mNumberToken(numberToken)
    , mValue(value) {}

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken *numberToken)
    : LiteralExpressionSyntax(numberToken, numberToken->getValue()) {}

SyntaxKind LiteralExpressionSyntax::getKind() {
    return LiteralExpression;
}

vector<SyntaxNode *> LiteralExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mNumberToken);
    return children;
}

SyntaxToken *LiteralExpressionSyntax::getNumberToken() {
    return mNumberToken;
}

void *LiteralExpressionSyntax::getValue() {
    return mValue;
}
