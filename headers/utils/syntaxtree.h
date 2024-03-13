#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

/**
 * @file syntaxtree.h
 * @brief Contains the declaration of the SyntaxTree class.
 */

 /**
  * @class SyntaxTree
  * @brief Represents a syntax tree for the XOR language.
  *
  * The SyntaxTree class is responsible for representing the syntax tree of a parsed input line.
  * It provides methods for retrieving the root expression syntax node and the end of file token.
  */
class SyntaxTree {
public:
    /**
     * Constructs a SyntaxTree object.
     * @param diagnostics The list of diagnostics associated with the syntax tree.
     * @param root The root expression syntax node of the syntax tree.
     * @param endOfFileToken The end of file token of the syntax tree.
     */
    SyntaxTree(vector<string> diagnostics, ExpressionSyntax *root, SyntaxToken endOfFileToken);

    /**
     * Gets the list of diagnostics associated with the syntax tree.
     * @return The list of diagnostics.
     */
    vector<string> getDiagnostics();

    /**
     * Gets the root expression syntax node of the syntax tree.
     * @return The root expression syntax node.
     */
    ExpressionSyntax *getRoot();

    /**
     * Gets the end of file token of the syntax tree.
     * @return The end of file token.
     */
    SyntaxToken getEndOfFileToken();

private:
    vector<string> mDiagnostics; // The list of diagnostics associated with the syntax tree.
    ExpressionSyntax *mRoot; // The root expression syntax node of the syntax tree.
    SyntaxToken mEndOfFileToken; // The end of file token of the syntax tree.
};
