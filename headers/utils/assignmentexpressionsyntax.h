#pragma once

#include "expressionsyntax.h"
#include "nameexpressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file assignmentexpressionsyntax.h
 * @brief Contains the declaration of the AssignmentExpressionSyntax class.
 */

 /**
  * @class AssignmentExpressionSyntax
  * @brief Represents a assignment expression in the syntax tree.
  *
  * This class represents a assignment expression in the syntax tree of a parsed input line.
  * It inherits from the ExpressionSyntax class and provides methods for getting the kind of the assignment expression,
  * retrieving the children of the assignment expression, and getting the assignment token.
  */
class AssignmentExpressionSyntax : public ExpressionSyntax {
public:
    /**
     * Constructs a AssignmentExpressionSyntax object with the given assignment token and value.
     * @param identifierToken The name token of the name expression.
     * @param equalsToken The assignment token of the assignment expression.
     * @param expression The expression of the assignment expression.
     */
    AssignmentExpressionSyntax(NameExpressionSyntax *identifierToken, SyntaxToken *equalsToken, ExpressionSyntax *expression);

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
    NameExpressionSyntax *getIdentifierToken();

    /**
     * Gets the assignment token of the assignment expression.
     * @return The assignment token.
     */
    SyntaxToken *getAssignToken();

    /**
     * Gets the expression of the assignment expression.
     * @return The expression.
     */
    ExpressionSyntax *getExpression();

private:
    NameExpressionSyntax *mIdentifierToken; // The name token of the name expression.
    SyntaxToken *mAssignToken;              // The assignment token of the assignment expression.
    ExpressionSyntax *mExpression;          // The expression of the assignment expression.
};
