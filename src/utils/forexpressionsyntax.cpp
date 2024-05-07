#include "../../headers/utils/forexpressionsyntax.h"

ForExpressionSyntax::ForExpressionSyntax(SyntaxToken *forToken, NameExpressionSyntax *identifier, SyntaxToken *colonToken, ExpressionSyntax *count, SyntaxToken *doToken, ExpressionSyntax *statment)
    : mForToken(forToken)
    , mIdentifier(identifier)
    , mColonToken(colonToken)
    , mCount(count)
    , mDoToken(doToken)
    , mStatment(statment) {}

SyntaxKind ForExpressionSyntax::getKind() {
    return SyntaxKind::LoopExpression;
}

std::vector<SyntaxNode *> ForExpressionSyntax::getChildren() {
    std::vector<SyntaxNode *> children;

    children.push_back(mForToken);
    children.push_back(mIdentifier);
    children.push_back(mColonToken);
    children.push_back(mCount);
    children.push_back(mDoToken);
    children.push_back(mStatment);

    return children;
}

SyntaxToken *ForExpressionSyntax::getForToken() {
    return mForToken;
}

NameExpressionSyntax *ForExpressionSyntax::getIdentifier() {
    return mIdentifier;
}

SyntaxToken *ForExpressionSyntax::getColonToken() {
    return mColonToken;
}

ExpressionSyntax *ForExpressionSyntax::getCount() {
    return mCount;
}

SyntaxToken *ForExpressionSyntax::getDoToken() {
    return mDoToken;
}

ExpressionSyntax *ForExpressionSyntax::getStatment() {
    return mStatment;
}
