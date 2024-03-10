#include "../../headers/utils/numberexpressionsyntax.h"

NumberExpressionSyntax::NumberExpressionSyntax(SyntaxToken *numberToken)
    : mNumberToken(numberToken) {}

SyntaxKind NumberExpressionSyntax::getKind() {
    return NumberExpressionToken;
}

vector<SyntaxNode *> NumberExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mNumberToken);
    return children;
}

SyntaxToken *NumberExpressionSyntax::getNumberToken() {
    return mNumberToken;
}
