#include "../../headers/utils/printexpression.h"

PrintExpressionSyntax::PrintExpressionSyntax(SyntaxToken *printToken, SyntaxToken *ColonToken, ExpressionSyntax *expression)
    : mPrintToken(printToken)
    , mColonToken(ColonToken)
    , mExpression(expression) {}

SyntaxKind PrintExpressionSyntax::getKind() {
    return PrintExpression;
}

vector<SyntaxNode *> PrintExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mPrintToken);
    children.push_back(mColonToken);
    children.push_back(mExpression);

    return children;
}

SyntaxToken *PrintExpressionSyntax::getPrintToken() {
    return mPrintToken;
}

SyntaxToken *PrintExpressionSyntax::getColonToken() {
    return mColonToken;
}

ExpressionSyntax *PrintExpressionSyntax::getExpression() {
    return mExpression;
}
