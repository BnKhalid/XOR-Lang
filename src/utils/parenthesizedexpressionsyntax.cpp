#include "../../headers/utils/parenthesizedexpressionsyntax.h"


ParenthesizedExpressionSyntax::ParenthesizedExpressionSyntax
(SyntaxToken *openParenthesisToken, ExpressionSyntax *expression, SyntaxToken *closeParenthesisToken)
    : mOpenParenthesisToken(openParenthesisToken)
    , mExpression(expression)
    , mCloseParenthesisToken(closeParenthesisToken) {}

SyntaxKind ParenthesizedExpressionSyntax::getKind() {
    return ParenthesizedExpression;
}

vector<SyntaxNode *> ParenthesizedExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;

    children.push_back(mOpenParenthesisToken);
    children.push_back(mExpression);
    children.push_back(mCloseParenthesisToken);
    
    return children;
}

SyntaxToken *ParenthesizedExpressionSyntax::getOpenParenthesisToken() {
    return mOpenParenthesisToken;
}

ExpressionSyntax *ParenthesizedExpressionSyntax::getExpression() {
    return mExpression;
}

SyntaxToken *ParenthesizedExpressionSyntax::getCloseParenthesisToken() {
    return mCloseParenthesisToken;
}
