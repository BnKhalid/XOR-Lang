#pragma once

#include <stdexcept>
#include <map>
#include "../utils/expressionsyntax.h"
#include "../utils/nameexpressionsyntax.h"
#include "../utils/assignmentexpressionsyntax.h"
#include "../utils/stringexpressionsyntax.h"
#include "../utils/literalexpressionsyntax.h"
#include "../utils/listexpressionsyntax.h"
#include "../utils/unaryexpressionsyntax.h"
#include "../utils/binaryexpressionsyntax.h"
#include "../utils/parenthesizedexpressionsyntax.h"
#include "../utils/ifexpressionsyntax.h"
#include "../utils/forexpressionsyntax.h"
#include "../utils/whileexpressionsyntax.h"

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
     * @param variables A pointer to the map of variables used in the expression.
     */
    Evaluator(ExpressionSyntax *root, map<string, Value> *variables, ErrorList *errors);

    /**
     * @brief Evaluates the root expression and returns the result.
     * @return The result of the evaluation.
     */
    Value evaluate();

    /**
     * @brief Evaluates the given statement node.
     * @param node The statement node to be evaluated.
     * @return The result of the evaluation.
     */
    Value evaluateStatement(ExpressionSyntax *node);

private:
    ExpressionSyntax *mRoot; // The root expression to be evaluated.
    map<string, Value> *mVariables; // The map of variables used in the expression.
    ErrorList *mErrors; // The list of errors that occurred during the evaluation.

    /**
     * @brief Recursively evaluates the given expression node.
     * @param node The expression node to be evaluated.
     * @return The result of the evaluation.
     */
    Value evaluateExpression(ExpressionSyntax *node);
};
