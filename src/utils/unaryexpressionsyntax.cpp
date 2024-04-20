#include "../../headers/utils/unaryexpressionsyntax.h"

UnaryExpressionSyntax::UnaryExpressionSyntax(SyntaxToken *operatorToken, ExpressionSyntax *operand)
    : mOperatorToken(operatorToken)
    , mOperand(operand) {}

SyntaxKind UnaryExpressionSyntax::getKind() {
    return UnaryExpression;
}

vector<SyntaxNode *> UnaryExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;

    children.push_back(mOperatorToken);
    children.push_back(mOperand);

    return children;
}

SyntaxToken *UnaryExpressionSyntax::getOperator() {
    return mOperatorToken;
}

ExpressionSyntax *UnaryExpressionSyntax::getOperand() {
    return mOperand;
}
