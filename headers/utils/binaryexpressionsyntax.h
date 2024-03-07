#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @class BinaryExpressionSyntax
 * Represents a binary expression in the syntax tree.
 * Inherits from ExpressionSyntax.
 */
class BinaryExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a BinaryExpressionSyntax object.
     * @param left The left expression of the binary expression.
     * @param operatorToken The operator token of the binary expression.
     * @param right The right expression of the binary expression.
     */
    BinaryExpressionSyntax(ExpressionSyntax *left, SyntaxToken *operatorToken, ExpressionSyntax *right);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind of the binary expression.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes representing the children of the binary expression.
     */
    std::vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the left expression of the binary expression.
     * @return The left expression.
     */
    ExpressionSyntax *getLeft();

    /**
     * Gets the operator token of the binary expression.
     * @return The operator token.
     */
    SyntaxToken *getOperator();

    /**
     * Gets the right expression of the binary expression.
     * @return The right expression.
     */
    ExpressionSyntax *getRight();

private:
    ExpressionSyntax *mLeft;        // The left expression of the binary expression.
    SyntaxToken *mOperatorToken;    // The operator token of the binary expression.
    ExpressionSyntax *mRight;       // The right expression of the binary expression.
};
