#include "../../headers/utils/interruptexpression.h"

InterruptExpressionSyntax::InterruptExpressionSyntax(SyntaxToken *interruptToken)
    : mInterruptToken(interruptToken) {}

SyntaxKind InterruptExpressionSyntax::getKind() {
    return InterruptExpression;
}

vector<SyntaxNode *> InterruptExpressionSyntax::getChildren() {
    return { mInterruptToken };
}

SyntaxToken *InterruptExpressionSyntax::getInterruptToken() {
    return mInterruptToken;
}
