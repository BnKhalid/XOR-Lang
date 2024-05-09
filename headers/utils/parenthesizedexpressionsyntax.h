#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file parenthesizedexpressionsyntax.h
 * @brief Contains the declaration of the ParenthesizedExpressionSyntax class.
 */

 /**
  * @class ParenthesizedExpressionSyntax
  * @brief Represents a parenthesized expression in the XOR language.
  *
  * The ParenthesizedExpressionSyntax class is responsible for representing a parenthesized expression in the XOR language.
  * It provides methods for retrieving the open parenthesis token, the expression inside the parentheses, and the close parenthesis token.
  */
class ParenthesizedExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Initializes a new instance of the ParenthesizedExpressionSyntax class.
     * @param openParenthesisToken The open parenthesis token.
     * @param expression The expression inside the parentheses.
     * @param closeParenthesisToken The close parenthesis token.
     */
    ParenthesizedExpressionSyntax(SyntaxToken *openParenthesisToken, ExpressionSyntax *expression, SyntaxToken *closeParenthesisToken);

    /**
     * Gets the kind of syntax node.
     * @return The syntax kind.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes.
     */
    vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the open parenthesis token.
     * @return The open parenthesis token.
     */
    SyntaxToken *getOpenParenthesisToken();

    /**
     * Gets the expression inside the parentheses.
     * @return The expression syntax.
     */
    ExpressionSyntax *getExpression();

    /**
     * Gets the close parenthesis token.
     * @return The close parenthesis token.
     */
    SyntaxToken *getCloseParenthesisToken();

private:
    SyntaxToken *mOpenParenthesisToken;     // The open parenthesis token.
    ExpressionSyntax *mExpression;          // The expression inside the parentheses.
    SyntaxToken *mCloseParenthesisToken;    // The close parenthesis token.
};
