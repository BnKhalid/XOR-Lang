#pragma once
#include <string>
#include "../../types/value.h"

using namespace std;

/**
 * Description
 *
 * @file headers/utils/parser.h
 */
class Parser {
public:
    /**
     * Description
     *
     * @param c c description
     * @return bool description
     */
    static bool isDigit(char c);

    /**
     * Description
     *
     * @param c c description
     * @return bool description
     */
    static bool isWhitespace(char c);

    /**
     * Description
     *
     * @param c c description
     * @return bool description
     */
    static bool isEndOfLine(char c);

    /**
     * Description
     *
     * @param c c description
     * @return bool description
     */
    static bool isLetter(char c);

    /**
     * Description
     *
     * @param s s description
     * @param val val description
     * @return bool description
     */
    static bool tryParseInt(string s, Value &val);
};

