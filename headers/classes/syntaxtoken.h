#pragma once
#include <string>
#include "../../types/value.h"
#include "../../enums/syntaxkind.h"

using namespace std;

/**
 * Description
 *
 * @file headers/classes/syntaxtoken.h
 */
class SyntaxToken {
public:
    /**
     * Construct `SyntaxToken` object
     *
     * @param kind kind description
     * @param position position description
     * @param text text description
     * @param val val description
     */
    SyntaxToken(SyntaxKind kind, int position, string text, Value val);

    /**
     * Construct `SyntaxToken` object
     *
     * @param kind kind description
     * @param position position description
     * @param text text description
     */
    SyntaxToken(SyntaxKind kind, int position, string text);

    /**
     * Description
     */
    void print();

    /**
     * Description
     * @return position description
     */
    int getPosition();

    /**
     * Description
     * @return kind description
     */
    SyntaxKind getKind();

    /**
     * Description
     * @return text description
     */
    string getText();

    /**
     * Description
     * @return value description
     */
    Value getValue();

private:
    /**
     * position description
     */
    int mPosition;

    /**
     * kind description
     */
    SyntaxKind mKind;

    /**
     * text description
     */
    string mText;

    /**
     * value description
     */
    Value mVal;

    /**
     * Description
     */
    void printValue();

    /**
     * Description
     *
     * @param kind kind description
     * @return string description
     */
    string printSyntaxKind(SyntaxKind kind);
};

