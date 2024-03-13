#pragma once

#include <string>
#include "../../types/value.h"
#include "../../headers/utils/syntaxnode.h"

using namespace std;

/**
 * @file syntaxtoken.h
 * @brief Contains the declaration of the SyntaxToken class.
 */

/**
 * @class SyntaxToken
 * @brief Represents a token in the syntax tree.
 * 
 * This class represents a token in the syntax tree of a parsed input line.
 * It inherits from the SyntaxNode class and provides methods for getting the kind, position, text, and value of the token.
 */
class SyntaxToken : public SyntaxNode {
public:
    /**
     * Constructs a `SyntaxToken` object with the specified kind, position, text, and value.
     *
     * @param kind The kind of the syntax token.
     * @param position The position of the syntax token.
     * @param text The text of the syntax token.
     * @param val The value of the syntax token.
     */
    SyntaxToken(SyntaxKind kind, int position, string text, Value val);

    /**
     * Constructs a `SyntaxToken` object with the specified kind, position, and text.
     *
     * @param kind The kind of the syntax token.
     * @param position The position of the syntax token.
     * @param text The text of the syntax token.
     */
    SyntaxToken(SyntaxKind kind, int position, string text);

    /**
     * Prints the syntax token.
     */
    void print();

    /**
     * Prints the value of the syntax token.
     */
    void printValue();

    /**
     * Gets the position of the syntax token.
     *
     * @return The position of the syntax token.
     */
    int getPosition();

    /**
     * Gets the kind of the syntax token.
     *
     * @return The kind of the syntax token.
     */
    SyntaxKind getKind();

    /**
     * Gets the text of the syntax token.
     *
     * @return The text of the syntax token.
     */
    string getText();

    /**
     * Gets the value of the syntax token.
     *
     * @return The value of the syntax token.
     */
    Value getValue();

private:
    /**
     * The kind of the syntax token.
     */
    SyntaxKind mKind;

    /**
     * The position of the syntax token.
     */
    int mPosition;

    /**
     * The text of the syntax token.
     */
    string mText;

    /**
     * The value of the syntax token.
     */
    Value mVal;

    /**
     * Returns a vector of SyntaxNode objects representing the children of this SyntaxToken.
     *
     * @return A vector of SyntaxNode objects representing the children of this SyntaxToken.
     */
    vector<SyntaxNode *> getChildren();
};

