#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file ifexpressionsyntax.h
 * @brief Contains the declaration of the IfExpressionSyntax class.
 */

 /**
  * @class IfExpressionSyntax
  * @brief Represents a if expression in the syntax tree.
  *
  * This class represents a if expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the if expression,
  * retrieving the children of the if expression, and getting the left expression, operator token, and right expression.
  */
class IfExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a IfExpressionSyntax object.
     * @param ifToken The if token of the if expression.
     * @param condition The condition of the if expression.
     * @param thenToken The then token of the if expression.
     * @param statment The statment of the if expression.
     */
    IfExpressionSyntax(SyntaxToken *ifToken, ExpressionSyntax *condition, SyntaxToken *thenToken, ExpressionSyntax *statment);

    IfExpressionSyntax(SyntaxToken *ifToken, ExpressionSyntax *condition, SyntaxToken *thenToken, ExpressionSyntax *statment, SyntaxToken *elseToken, ExpressionSyntax *elseStatment);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind of the if expression.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes representing the children of the if expression.
     */
    std::vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the if token of the if expression.
     * @return The if token.
     */
    SyntaxToken *getIfToken();

    /**
     * Gets the condition of the if expression.
     * @return The condition.
     */
    ExpressionSyntax *getCondition();

    /**
     * Gets the then token of the if expression.
     * @return The then token.
     */
    SyntaxToken *getThenToken();

    /**
     * Gets the statment of the if expression.
     * @return The statment.
     */
    ExpressionSyntax *getStatment();

    /**
     * Gets the else token of the if expression.
     * @return The else token.
     */
    SyntaxToken *getElseToken();

    /**
     * Gets the statment of the if expression.
     * @return The statment.
     */
    ExpressionSyntax *getElseStatment();

private:
    SyntaxToken *mIfToken;              // The if token of the if expression.
    ExpressionSyntax *mCondition;       // The condition of the if expression.
    SyntaxToken *mThenToken;            // The then token of the if expression.
    ExpressionSyntax *mStatment;        // The statment of the if expression.
    SyntaxToken *mElseToken;            // The else token of the if expression.
    ExpressionSyntax *mElseStatment;    // The statment of the if expression.
};
