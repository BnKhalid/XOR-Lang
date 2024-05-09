#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file printexpressionsyntax.h
 * @brief Contains the declaration of the PrintExpressionSyntax class.
 */

 /**
  * @class PrintExpressionSyntax
  * @brief Represents a print expression in the syntax tree.
  *
  * This class represents a print expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the print expression,
  * retrieving the children of the print expression, and getting the print token.
  */
class PrintExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a PrintExpressionSyntax object with the given print token.
     * @param printToken The token representing the print.
     */
    PrintExpressionSyntax(SyntaxToken *printToken, SyntaxToken *ColonToken, ExpressionSyntax *expression);

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
     * Gets the print token of the print expression.
     * @return The print token.
     */
    SyntaxToken *getPrintToken();

    /**
     * Gets the colon token of the print expression.
     * @return The colon token.
     */
    SyntaxToken *getColonToken();

    /**
     * Gets the expression of the print expression.
     * @return The expression.
     */
    ExpressionSyntax *getExpression();

private:
    SyntaxToken *mPrintToken;       // The token representing the print.
    SyntaxToken *mColonToken;       // The token representing the colon.
    ExpressionSyntax *mExpression;  // The expression to print.
};
