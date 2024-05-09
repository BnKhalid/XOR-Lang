#pragma once
#include <string>

using namespace std;



/**
 * @file headers/utils/valueparser.h
 * @brief The Value Parser class provides utility functions for parsing characters and strings.
 */

 /**
  * @class ValueParser
  * @brief The Value Parser class provides utility functions for parsing characters and strings.
  *
  * This class contains static member functions that can be used to check if a character is a digit,
  * whitespace, end of line, or letter. It also provides a function to try parsing an integer from a string.
  */
class ValueParser {
public:
    /**
     * @brief Check if a character is a digit.
     *
     * @param c The character to check.
     * @return true if the character is a digit, false otherwise.
     */
    static bool isDigit(char c);

    /**
     * @brief Check if a character is a whitespace.
     *
     * @param c The character to check.
     * @return true if the character is a whitespace, false otherwise.
     */
    static bool isWhitespace(char c);

    /**
     * @brief Check if a character is an end of line character.
     *
     * @param c The character to check.
     * @return true if the character is an end of line character, false otherwise.
     */
    static bool isEndOfLine(char c);

    /**
     * @brief Check if a character is a letter.
     *
     * @param c The character to check.
     * @return true if the character is a letter, false otherwise.
     */
    static bool isLetter(char c);

    /**
     * @brief Try parsing an integer from a string.
     *
     * This function attempts to parse an integer from the given string and stores the result in the provided Value object.
     *
     * @param s The string to parse.
     * @param val The Value object to store the parsed integer.
     * @return true if the parsing is successful, false otherwise.
     */
    static bool tryParseInt(string s, void **val);
};
