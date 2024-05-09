#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file interruptexpressionsyntax.h
 * @brief Contains the declaration of the InterruptExpressionSyntax class.
 */

 /**
  * @class InterruptExpressionSyntax
  * @brief Represents a interrupt expression in the syntax tree.
  *
  * This class represents a interrupt expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the interrupt expression,
  * retrieving the children of the interrupt expression, and getting the interrupt token.
  */
class InterruptExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a InterruptExpressionSyntax object with the given interrupt token.
     * @param interruptToken The token representing the interrupt.
     */
    InterruptExpressionSyntax(SyntaxToken *interruptToken);

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
     * Gets the interrupt token of the interrupt expression.
     * @return The interrupt token.
     */
    SyntaxToken *getInterruptToken();

private:
    SyntaxToken *mInterruptToken; // The token representing the interrupt.
};
