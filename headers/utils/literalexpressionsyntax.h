#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file literalexpressionsyntax.h
 * @brief Contains the declaration of the LiteralExpressionSyntax class.
 */

 /**
  * @class LiteralExpressionSyntax
  * @brief Represents a number expression in the syntax tree.
  *
  * This class represents a number expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the number expression,
  * retrieving the children of the number expression, and getting the number token.
  */
class LiteralExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a LiteralExpressionSyntax object with the given number token.
     * @param numberToken The token representing the number.
     */
    LiteralExpressionSyntax(SyntaxToken *numberToken);

    /**
     * Constructs a LiteralExpressionSyntax object with the given number token and value.
     * @param numberToken The token representing the number.
     * @param value The value of the number.
     */
    LiteralExpressionSyntax(SyntaxToken *numberToken, Value value);

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

    /**
     * Gets the value of the number expression.
     * @return The value.
     */
    Value getValue();

private:
    SyntaxToken *mNumberToken;  // The token representing the number.
    Value mValue;               // The value of the number.
};
