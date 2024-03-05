#pragma once
#include "string"
#include "../classes/syntaxtoken.h"

using namespace std;

/**
 * Description
 *
 * @file headers/utils/lexer.h
 */
class Lexer {
public:
    /**
     * Construct `Lexer` objec
     *
     * @param line line description
     */
    Lexer(string line);

    /**
     * Description
     *
     * @return token description
     */
    SyntaxToken nextToken();

private:
    /**
     * line description
     */
    string mLine;

    /**
     * position description
     */
    int position;

    /**
     * Description
     *
     * @return character description
     */
    char current();

    /**
     * Description
     *
     * @return integer description
     */
    int nextPos();
};

