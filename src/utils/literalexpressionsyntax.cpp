#include "../../headers/utils/literalexpressionsyntax.h"

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken *numberToken)
    : LiteralExpressionSyntax(numberToken, numberToken->getValue()) {}

LiteralExpressionSyntax::LiteralExpressionSyntax(SyntaxToken *numberToken, Value value)
    : mNumberToken(numberToken)
    , mValue(value) {}

SyntaxKind LiteralExpressionSyntax::getKind() {
    return LiteralExpression;
}

vector<SyntaxNode *> LiteralExpressionSyntax::getChildren() {
    return { mNumberToken };
}

SyntaxToken *LiteralExpressionSyntax::getNumberToken() {
    return mNumberToken;
}

Value LiteralExpressionSyntax::getValue() {
    return mValue;
}
