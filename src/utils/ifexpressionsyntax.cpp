#include "../../headers/utils/ifexpressionsyntax.h"

IfExpressionSyntax::IfExpressionSyntax(SyntaxToken *ifToken, ExpressionSyntax *condition, SyntaxToken *thenToken, ExpressionSyntax *statment)
    : IfExpressionSyntax(ifToken, condition, thenToken, statment, nullptr, nullptr) {}

IfExpressionSyntax::IfExpressionSyntax
(SyntaxToken *ifToken, ExpressionSyntax *condition, SyntaxToken *thenToken, ExpressionSyntax *statment, SyntaxToken *elseToken, ExpressionSyntax *elseStatment)
    : mIfToken(ifToken)
    , mCondition(condition)
    , mThenToken(thenToken)
    , mStatment(statment)
    , mElseToken(elseToken)
    , mElseStatment(elseStatment) {}

SyntaxKind IfExpressionSyntax::getKind() {
    return IfExpression;
}

std::vector<SyntaxNode *> IfExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mIfToken);
    children.push_back(mCondition);
    children.push_back(mThenToken);
    children.push_back(mStatment);
    return children;
}

SyntaxToken *IfExpressionSyntax::getIfToken() {
    return mIfToken;
}

ExpressionSyntax *IfExpressionSyntax::getCondition() {
    return mCondition;
}

SyntaxToken *IfExpressionSyntax::getThenToken() {
    return mThenToken;
}

ExpressionSyntax *IfExpressionSyntax::getStatment() {
    return mStatment;
}

SyntaxToken *IfExpressionSyntax::getElseToken() {
    return mElseToken;
}

ExpressionSyntax *IfExpressionSyntax::getElseStatment() {
    return mElseStatment;
}
