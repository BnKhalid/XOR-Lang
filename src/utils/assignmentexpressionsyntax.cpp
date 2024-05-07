#include "../../headers/utils/assignmentexpressionsyntax.h"

AssignmentExpressionSyntax::AssignmentExpressionSyntax(NameExpressionSyntax *identifierToken, SyntaxToken *equalsToken, ExpressionSyntax *expression)
    : mIdentifierToken(identifierToken)
    , mAssignToken(equalsToken)
    , mExpression(expression) {}

SyntaxKind AssignmentExpressionSyntax::getKind() {
    return AssignmentExpression;
}

vector<SyntaxNode *> AssignmentExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;

    children.push_back(mIdentifierToken);
    children.push_back(mAssignToken);
    children.push_back(mExpression);

    return children;
}

NameExpressionSyntax *AssignmentExpressionSyntax::getIdentifierToken() {
    return mIdentifierToken;
}

SyntaxToken *AssignmentExpressionSyntax::getAssignToken() {
    return mAssignToken;
}

ExpressionSyntax *AssignmentExpressionSyntax::getExpression() {
    return mExpression;
}

