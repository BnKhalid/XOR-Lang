#pragma once
#include <string>
#include "../../types/value.h"
#include "../../enums/syntaxkind.h"

using namespace std;

/**
 * Represents a syntax token in the XOR language.
 *
 * @class SyntaxToken
 * @file headers/classes/syntaxtoken.h
 */
class SyntaxToken {
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
     * The position of the syntax token.
     */
    int mPosition;

    /**
     * The kind of the syntax token.
     */
    SyntaxKind mKind;

    /**
     * The text of the syntax token.
     */
    string mText;

    /**
     * The value of the syntax token.
     */
    Value mVal;

    /**
     * Prints the value of the syntax token.
     */
    void printValue();

    /**
     * Returns a string representation of the given syntax kind.
     *
     * @param kind The syntax kind.
     * @return The string representation of the syntax kind.
     */
    string printSyntaxKind(SyntaxKind kind);
};

