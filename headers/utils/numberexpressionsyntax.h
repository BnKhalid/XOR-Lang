#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file numberexpressionsyntax.h
 * @brief Contains the declaration of the NumberExpressionSyntax class.
 */

 /**
  * @class NumberExpressionSyntax
  * @brief Represents a number expression in the syntax tree.
  *
  * This class represents a number expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the number expression,
  * retrieving the children of the number expression, and getting the number token.
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
