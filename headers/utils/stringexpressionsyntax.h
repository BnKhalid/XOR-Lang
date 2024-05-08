#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file stringexpressionsyntax.h
 * @brief Contains the declaration of the StringExpressionSyntax class.
 */

 /**
  * @class StringExpressionSyntax
  * @brief Represents a string expression in the syntax tree.
  *
  * This class represents a string expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the string expression,
  * retrieving the children of the string expression, and getting the string token.
  */
class StringExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a StringExpressionSyntax object with the given string token.
     * @param stringToken The token representing the string.
     */
    StringExpressionSyntax(SyntaxToken *stringToken);

    /**
     * Constructs a StringExpressionSyntax object with the given string token and value.
     * @param stringToken The token representing the string.
     * @param value The value of the string.
     */
    StringExpressionSyntax(SyntaxToken *stringToken, Value value);

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
     * Gets the string token of the string expression.
     * @return The string token.
     */
    SyntaxToken *getStringToken();

    /**
     * Gets the value of the string expression.
     * @return The value.
     */
    Value getValue();

private:
    /**
     * Represents a string token in the syntax tree.
     */
    SyntaxToken *mStringToken;

    Value mValue;
};
