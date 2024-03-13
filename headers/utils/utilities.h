#pragma once

#include "syntaxnode.h"
#include "binaryexpressionsyntax.h"
#include "numberexpressionsyntax.h"

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
    static string printSyntaxKind(SyntaxKind kind);

    /**
     * @brief Prints the syntax tree starting from the given node.
     * @param node The root node of the syntax tree.
     * @param intend The indentation string to be used for formatting.
     * @param isLast A flag indicating whether the current node is the last child of its parent.
     */
    static void print(SyntaxNode *node, string intend, bool isLast);
};
