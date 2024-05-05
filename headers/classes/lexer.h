#pragma once

#include "../utils/syntaxtoken.h"
#include "../utils/valueparser.h"
#include "../utils/utilities.h"
#include "../errors/errorlist.h"
#include "../errors/runtimeerror.h"
#include "../errors/illigalcharactererror.h"

using namespace std;

/**
 * @file lexer.h
 * @brief Contains the declaration of the Lexer class.
 */

 /**
  * @class Lexer
  * @brief The Lexer class represents a lexer for tokenizing input strings.
  *
  * This class is responsible for breaking down an input string into individual tokens.
  * It provides methods for retrieving the next token from the input string.
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
    SyntaxToken lex();

    /**
     * @brief Retrieves the errors generated during tokenization.
     *
     * @return A vector of strings representing the errors.
     */
    ErrorList getErrors();

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
     * @brief The errors generated during tokenization.
     */
    ErrorList mErrors;

    /**
     * @brief Retrieves the character at the specified offset from the current position in the input string.
     *
     * @param offset The offset from the current position.
     * @return The character at the specified offset.
     */
    char peek(int offset);

    /**
     * @brief Retrieves the current character at the current position in the input string.
     *
     * @return The current character at the current position.
     */
    char current();

    /**
     * @brief Retrieves the character at the next position in the input string.
     *
     * @return The character at the next position.
     */
    char lookAhead();

    /**
     * @brief Advances the position to the next character in the input string.
     *
     * @return The next position after advancing.
     */
    int nextPos();
};
