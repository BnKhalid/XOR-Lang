#pragma once

#include <vector>
#include "../../types/value.h"
#include "../../enums/syntaxkind.h"

using namespace std;

/**
 * @file syntaxnode.h
 * @brief Contains the declaration of the SyntaxNode class.
 */

 /**
  * @class SyntaxNode
  * @brief Base class for all syntax nodes in the XOR language.
  *
  * The `SyntaxNode` class represents a node in the abstract syntax tree (AST) of the XOR language.
  * It provides common functionality and properties that are shared by all syntax nodes.
  */
class SyntaxNode {
public:
    /**
     * @brief Gets the kind of the syntax node.
     * @return The kind of the syntax node.
     */
    virtual SyntaxKind getKind() = 0;

    /**
     * @brief Gets the children of the syntax node.
     * @return A vector of pointers to the children syntax nodes.
     */
    virtual vector<SyntaxNode *> getChildren() = 0;
};
