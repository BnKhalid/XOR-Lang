#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file nameexpressionsyntax.h
 * @brief Contains the declaration of the NameExpressionSyntax class.
 */

 /**
  * @class NameExpressionSyntax
  * @brief Represents a name expression in the syntax tree.
  *
  * This class represents a name expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the name expression,
  * retrieving the children of the name expression, and getting the name token.
  */
class NameExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a NameExpressionSyntax object with the given name token.
     * @param nameToken The token representing the name.
     */
    NameExpressionSyntax(SyntaxToken *nameToken);
    /**
     * Constructs a NameExpressionSyntax object with the given name token.
     * @param nameToken The token representing the name.
     * @param value The value of the name.
     */
    NameExpressionSyntax(SyntaxToken *nameToken, void *value);

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
     * Gets the name token of the name expression.
     * @return The name token.
     */
    SyntaxToken *getIdentifierToken();

    /**
     * Gets the value of the number expression.
     * @return The value.
     */
    void *getValue();

private:
    /**
     * Represents a name token in the syntax tree.
     */
    SyntaxToken *mIdenrifierToken;

    /**
     * Represents the value of the name expression.
     */
    void *mValue;
};
