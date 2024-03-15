#pragma once

#include <stdexcept>
#include "literalexpressionsyntax.h"
#include "unaryexpressionsyntax.h"
#include "binaryexpressionsyntax.h"
#include "parenthesizedexpressionsyntax.h"
#include "expressionsyntax.h"

/**
 * @file evaluator.h
 * @brief Contains the declaration of the Evaluator class.
 */

 /**
  * @class Evaluator
  * @brief Provides methods for evaluating the syntax tree of a parsed input line.
  *
  * This class provides methods for evaluating the syntax tree of a parsed input line.
  * It contains a single static method that takes a syntax node as input and returns the result of the evaluation.
  */
class Evaluator {
public:
    /**
     * @brief Constructs an Evaluator object with the given root expression.
     * @param root The root expression to be evaluated.
     */
    Evaluator(ExpressionSyntax *root);

    /**
     * @brief Evaluates the root expression and returns the result.
     * @return The result of the evaluation.
     */
    int evaluate();

private:
    ExpressionSyntax *mRoot; // The root expression to be evaluated.

    /**
     * @brief Recursively evaluates the given expression node.
     * @param node The expression node to be evaluated.
     * @return The result of the evaluation.
     */
    int evaluateExpression(ExpressionSyntax *node);
};
