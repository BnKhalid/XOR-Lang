#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file listexpressionsyntax.h
 * @brief Contains the declaration of the ListExpressionSyntax class.
 */

 /**
  * @class ListExpressionSyntax
  * @brief Represents a list expression in the syntax tree.
  *
  * This class represents a list expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the list expression,
  * retrieving the children of the list expression, and getting the list token.
  */
class ListExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a ListExpressionSyntax object with the given list token and value.
     * @param openSquareBrackets The open square brackets token of the list expression.
     * @param listObjects The objects of the list expression.
     * @param closequareBrackets The close square brackets token of the list expression.
     */
    ListExpressionSyntax(SyntaxToken *openSquareBrackets, vector<ExpressionSyntax *> listObjects, SyntaxToken *closequareBrackets);

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
     * Gets the open square brackets token of the list expression.
     * @return The open square brackets token.
     */
    SyntaxToken *getOpenSquareBrackets();

    /**
     * Gets the objects of the list expression.
     * @return A vector of expression syntax nodes.
     */
    vector<ExpressionSyntax *> getListObjects();

    /**
     * Gets the close square brackets token of the list expression.
     * @return The close square brackets token.
     */
    SyntaxToken *getCloseSquareBrackets();

private:
    SyntaxToken *mOpenSquareBrackets;           // The open square brackets token of the list expression.
    vector<ExpressionSyntax *> mListObjects;    // The objects of the list expression.
    SyntaxToken *mCloseSquareBrackets;          // The close square brackets token of the list expression.
};
