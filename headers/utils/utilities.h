#pragma once

#include <iostream>
#include "syntaxnode.h"
#include "binaryexpressionsyntax.h"
#include "literalexpressionsyntax.h"

/**
 * @file utilities.h
 * @brief Contains the declaration of the Utilities class.
 */

 /**
  * @class Utilities
  * @brief A utility class that provides helper functions for various operations.
  */
class Utilities {
public:
    /**
     * @brief Prints the syntax kind of a given node.
     * @param kind The syntax kind to be printed.
     * @return A string representation of the syntax kind.
     */
    static string parseSyntaxKind(SyntaxKind kind);

    /**
     * @brief Gets the syntax kind of a given token.
     * @param text The text of the token.
     * @return The syntax kind of the token.
     */
    static SyntaxKind getKind(string text);

    /**
     * @brief Prints the syntax tree starting from the given node.
     * @param node The root node of the syntax tree.
     * @param intend The indentation string to be used for formatting.
     * @param isLast A flag indicating whether the current node is the last child of its parent.
     */
    static void print(SyntaxNode *node, string intend, bool isLast);

    /**
     * @brief Prints the value of a given token.
     * @param val The value to be printed.
     */
    static void printValue(Value al);

    /**
     * @brief Prints the list of errors stored in the error list.
     */
    static void printErrors(ErrorList errors);

    /**
     * @brief Prints the result of the evaluation.
     * @param result The result to be printed.
     */
    static void printResult(Value result);
};
