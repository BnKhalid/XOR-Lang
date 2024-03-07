#pragma once

#include "syntaxnode.h"

/**
 * @class ExpressionSyntax
 * @brief Base class for expression syntax nodes.
 *
 * This class represents a syntax node that represents an expression in the XOR language.
 * It inherits from the SyntaxNode class and provides virtual functions for getting the kind of the expression
 * and retrieving the children of the expression.
 */
class ExpressionSyntax : public SyntaxNode {
public:
    /**
     * @brief Get the kind of the expression.
     * @return The kind of the expression as a SyntaxKind enum value.
     */
    virtual SyntaxKind getKind() = 0;

    /**
     * @brief Get the children of the expression.
     * @return A vector of SyntaxNode pointers representing the children of the expression.
     */
    virtual vector<SyntaxNode *> getChildren() = 0;
};
