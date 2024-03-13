#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

class ParenthesizedExpressionSyntax : public ExpressionSyntax {
public:
    ParenthesizedExpressionSyntax(SyntaxToken *openParenthesisToken, ExpressionSyntax *expression, SyntaxToken *closeParenthesisToken);
    SyntaxKind getKind() override;
    vector<SyntaxNode *> getChildren() override;
    SyntaxToken *getOpenParenthesisToken();
    ExpressionSyntax *getExpression();
    SyntaxToken *getCloseParenthesisToken();
private:
    SyntaxToken *mOpenParenthesisToken;
    ExpressionSyntax *mExpression;
    SyntaxToken *mCloseParenthesisToken;
};
