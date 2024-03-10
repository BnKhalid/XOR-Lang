#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * Represents a syntax node for a number expression.
 * Inherits from ExpressionSyntax.
 */
class NumberExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a NumberExpressionSyntax object with the given number token.
     * @param numberToken The token representing the number.
     */
    NumberExpressionSyntax(SyntaxToken *numberToken);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes.
     */
    vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the number token of the number expression.
     * @return The number token.
     */
    SyntaxToken *getNumberToken();

private:
    /**
     * Represents a number token in the syntax tree.
     */
    SyntaxToken *mNumberToken;
};
