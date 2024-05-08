#include "../../headers/utils/whileexpressionsyntax.h"

WhileExpressionSyntax::WhileExpressionSyntax(SyntaxToken *whileToken, ExpressionSyntax *condition, SyntaxToken *doToken, ExpressionSyntax *statment)
    : mWhileToken(whileToken)
    , mCondition(condition)
    , mDoToken(doToken)
    , mStatment(statment) {}

SyntaxKind WhileExpressionSyntax::getKind() {
    return SyntaxKind::LoopExpression;
}

std::vector<SyntaxNode *> WhileExpressionSyntax::getChildren() {
    std::vector<SyntaxNode *> children;

    children.push_back(mWhileToken);
    children.push_back(mCondition);
    children.push_back(mDoToken);
    children.push_back(mStatment);

    return children;
}

SyntaxToken *WhileExpressionSyntax::getWhileToken() {
    return mWhileToken;
}

ExpressionSyntax *WhileExpressionSyntax::getCondition() {
    return mCondition;
}

SyntaxToken *WhileExpressionSyntax::getDoToken() {
    return mDoToken;
}

ExpressionSyntax *WhileExpressionSyntax::getStatment() {
    return mStatment;
}
