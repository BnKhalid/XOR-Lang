#pragma once

#include "expressionsyntax.h"
#include "nameexpressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file whileexpressionsyntax.h
 * @brief Contains the declaration of the WhileExpressionSyntax class.
 */

 /**
  * @class WhileExpressionSyntax
  * @brief Represents a while expression in the syntax tree.
  *
  * This class represents a while expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the while expression,
  * getting the children of the while expression, and getting the while token, condition, do token, and statment of the while expression.
  */
class WhileExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a WhileExpressionSyntax object.
     * @param whileToken The while token of the while expression.
     * @param condition The condition of the while expression.
     * @param doToken The do token of the while expression.
     * @param statment The statment of the while expression.
     */
    WhileExpressionSyntax(SyntaxToken *whileToken, ExpressionSyntax *condition, SyntaxToken *doToken, ExpressionSyntax *statment);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind of the while expression.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes representing the children of the while expression.
     */
    std::vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the while token of the while expression.
     * @return The while token.
     */
    SyntaxToken *getWhileToken();

    /**
     * Gets the condition of the while expression.
     * @return The condition.
     */
    ExpressionSyntax *getCondition();

    /**
     * Gets the do token of the while expression.
     * @return The do token.
     */
    SyntaxToken *getDoToken();

    /**
     * Gets the statment of the while expression.
     * @return The statment.
     */
    ExpressionSyntax *getStatment();

private:
    SyntaxToken *mWhileToken;       // The while token of the while expression.
    ExpressionSyntax *mCondition;   // The condition of the while expression.
    SyntaxToken *mDoToken;          // The do token of the while expression.
    ExpressionSyntax *mStatment;    // The statment of the while expression.
};
