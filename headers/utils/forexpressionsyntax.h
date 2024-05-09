#pragma once

#include "expressionsyntax.h"
#include "nameexpressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file forexpressionsyntax.h
 * @brief Contains the declaration of the ForExpressionSyntax class.
 */

 /**
  * @class ForExpressionSyntax
  * @brief Represents a for expression in the syntax tree.
  *
  * This class represents a for expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the for expression,
  * getting the children of the for expression, and getting the for token, identifier, colon token, range, do token, and statment of the for expression.
  */
class ForExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a ForExpressionSyntax object.
     * @param forToken The for token of the for expression.
     * @param identifier The identifier of the for expression.
     * @param colonToken The colon token of the for expression.
     * @param range The iterations range expression of the for expression.
     * @param doToken The do token of the for expression.
     * @param statment The statment of the for expression.
     */
    ForExpressionSyntax(SyntaxToken *forToken, NameExpressionSyntax *identifier, SyntaxToken *colonToken, ExpressionSyntax *range, SyntaxToken *doToken, ExpressionSyntax *statment);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind of the for expression.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes representing the children of the for expression.
     */
    std::vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the for token of the for expression.
     * @return The for token.
     */
    SyntaxToken *getForToken();

    /**
     * Gets the identifier of the for expression.
     * @return The identifier.
     */
    NameExpressionSyntax *getIdentifier();

    /**
     * Gets the colon token of the for expression.
     * @return The colon token.
     */
    SyntaxToken *getColonToken();

    /**
     * Gets the iterations range expression of the for expression.
     * @return The range.
     */
    ExpressionSyntax *getCount();

    /**
     * Gets the do token of the for expression.
     * @return The do token.
     */
    SyntaxToken *getDoToken();

    /**
     * Gets the statment of the for expression.
     * @return The statment.
     */
    ExpressionSyntax *getStatment();

private:
    SyntaxToken *mForToken;             // The for token of the for expression.
    NameExpressionSyntax *mIdentifier;  // The identifier of the for expression.
    SyntaxToken *mColonToken;           // The colon token of the for expression.
    ExpressionSyntax *mRange;           // The iterations range expression of the for expression.
    SyntaxToken *mDoToken;              // The do token of the for expression.
    ExpressionSyntax *mStatment;        // The statment of the for expression.
};
