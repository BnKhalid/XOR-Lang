#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file indexexpressionsyntax.h
 * @brief Contains the declaration of the IndexExpressionSyntax class.
 */

 /**
  * @class IndexExpressionSyntax
  * @brief Represents a index expression in the syntax tree.
  *
  * This class represents a index expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the index expression,
  * retrieving the children of the index expression, and getting the index token.
  */
class IndexExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a IndexExpressionSyntax object with the given index token and value.
     * @param Iteratable The iteratable object of the index expression.
     * @param openSquareBrackets The open square brackets token of the index expression.
     * @param indexObjects The objects of the index expression.
     * @param closequareBrackets The close square brackets token of the index expression.
     */
    IndexExpressionSyntax(ExpressionSyntax *Iteratable, SyntaxToken *openSquareBrackets, ExpressionSyntax *index, SyntaxToken *closequareBrackets);

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
     * Gets the iteratable object of the index expression.
     * @return The iteratable object.
     */
    ExpressionSyntax *getIteratable();

    /**
     * Gets the open square brackets token of the index expression.
     * @return The open square brackets token.
     */
    SyntaxToken *getOpenSquareBrackets();

    /**
     * Gets the objects of the index expression.
     * @return A vector of expression syntax nodes.
     */
    ExpressionSyntax *getIndex();

    /**
     * Gets the close square brackets token of the index expression.
     * @return The close square brackets token.
     */
    SyntaxToken *getCloseSquareBrackets();

private:
    ExpressionSyntax *mIteratable;      // The iteratable object of the index expression.
    SyntaxToken *mOpenSquareBrackets;   // The open square brackets token of the index expression.
    ExpressionSyntax *mIndex;           // The objects of the index expression.
    SyntaxToken *mCloseSquareBrackets;  // The close square brackets token of the index expression.
};
