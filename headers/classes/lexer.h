#pragma once

#include "../utils/syntaxtoken.h"

using namespace std;

/**
 * @brief The Lexer class represents a lexer for tokenizing input strings.
 *
 * This class is responsible for breaking down an input string into individual tokens.
 * It provides methods for retrieving the next token from the input string.
 *
 * @file headers/utils/lexer.h
 */
class Lexer {
public:
    /**
     * @brief Constructs a Lexer object with the given input string.
     *
     * @param line The input string to be tokenized.
     */
    Lexer(string line);

    /**
     * @brief Retrieves the next token from the input string.
     *
     * This method returns the next token from the input string and advances the internal position.
     *
     * @return The next token from the input string.
     */
    SyntaxToken nextToken();

private:
    /**
     * @brief The input string to be tokenized.
     */
    string mLine;

    /**
     * @brief The current position in the input string.
     */
    int position;

    /**
     * @brief Retrieves the current character at the current position in the input string.
     *
     * @return The current character at the current position.
     */
    char current();

    /**
     * @brief Advances the position to the next character in the input string.
     *
     * @return The next position after advancing.
     */
    int nextPos();
};

