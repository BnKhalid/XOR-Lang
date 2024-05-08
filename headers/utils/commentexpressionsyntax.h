#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file commentlexpressionsyntax.h
 * @brief Contains the declaration of the CommentExpressionSyntax class.
 */

 /**
  * @class CommentExpressionSyntax
  * @brief Represents a comment expression in the syntax tree.
  *
  * This class represents a comment expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the comment expression,
  * retrieving the children of the comment expression, and getting the comment token.
  */
class CommentExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a CommentExpressionSyntax object with the given comment token.
     * @param commentToken The token representing the comment.
     */
    CommentExpressionSyntax(SyntaxToken *commentToken);

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
     * Gets the comment token of the comment expression.
     * @return The comment token.
     */
    SyntaxToken *getCommentToken();

private:
    SyntaxToken *mCommentToken; // The token representing the comment.
};
