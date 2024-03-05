#include "../../headers/utils/parser.h"

using namespace std;

bool Parser::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Parser::isWhitespace(char c) {
    return c == ' ' || c == '\t';
}

bool Parser::isEndOfLine(char c) {
    return c == '\n' || c == '\r';
}

bool Parser::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Parser::tryParseInt(string s, Value &val) {
    for (char c : s)
        if (isDigit(c) == false)
            return false;

    val.pInt = new int;
    *val.pInt = stoi(s);

    return true;
}

