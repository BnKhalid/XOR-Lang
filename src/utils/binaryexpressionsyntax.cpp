#include "../../headers/utils/binaryexpressionsyntax.h"

BinaryExpressionSyntax::BinaryExpressionSyntax(ExpressionSyntax *left, SyntaxToken *operatorToken, ExpressionSyntax *right)
    : mLeft(left)
    , mOperatorToken(operatorToken)
    , mRight(right) {}

SyntaxKind BinaryExpressionSyntax::getKind() {
    return BinaryExpression;
}

vector<SyntaxNode *> BinaryExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;

    children.push_back(mLeft);
    children.push_back(mOperatorToken);
    children.push_back(mRight);

    return children;
}

ExpressionSyntax *BinaryExpressionSyntax::getLeft() {
    return mLeft;
}

SyntaxToken *BinaryExpressionSyntax::getOperator() {
    return mOperatorToken;
}

ExpressionSyntax *BinaryExpressionSyntax::getRight() {
    return mRight;
}
