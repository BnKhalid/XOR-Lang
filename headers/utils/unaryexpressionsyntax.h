#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file unaryexpressionsyntax.h
 * @brief Contains the declaration of the UnaryExpressionSyntax class.
 */

 /**
  * @class UnaryExpressionSyntax
  * @brief Represents a unary expression in the syntax tree.
  *
  * This class represents a unary expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the unary expression,
  * retrieving the children of the unary expression, and getting the operator token, and operand expression.
  */
class UnaryExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a UnaryExpressionSyntax object.
     * @param operatorToken The operator token of the unary expression.
     * @param operand The operand expression of the unary expression.
     */
    UnaryExpressionSyntax(SyntaxToken *operatorToken, ExpressionSyntax *operand);

    /**
     * Gets the kind of the syntax node.
     * @return The syntax kind of the unary expression.
     */
    SyntaxKind getKind() override;

    /**
     * Gets the children of the syntax node.
     * @return A vector of syntax nodes representing the children of the unary expression.
     */
    std::vector<SyntaxNode *> getChildren() override;

    /**
     * Gets the operator token of the unary expression.
     * @return The operator token.
     */
    SyntaxToken *getOperator();

    /**
     * Gets the operand expression of the unary expression.
     * @return The operand expression.
     */
    ExpressionSyntax *getOperand();

private:
    SyntaxToken *mOperatorToken;    // The operator token of the unary expression.
    ExpressionSyntax *mOperand;     // The operand expression of the unary expression.
};
