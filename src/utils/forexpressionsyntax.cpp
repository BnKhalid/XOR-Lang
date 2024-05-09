#include "../../headers/utils/forexpressionsyntax.h"

ForExpressionSyntax::ForExpressionSyntax(SyntaxToken *forToken, NameExpressionSyntax *identifier, SyntaxToken *colonToken, ExpressionSyntax *range, SyntaxToken *doToken, ExpressionSyntax *statment)
    : mForToken(forToken)
    , mIdentifier(identifier)
    , mColonToken(colonToken)
    , mRange(range)
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
    children.push_back(mRange);
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
    return mRange;
}

SyntaxToken *ForExpressionSyntax::getDoToken() {
    return mDoToken;
}

ExpressionSyntax *ForExpressionSyntax::getStatment() {
    return mStatment;
}
