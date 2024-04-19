#include "../../headers/utils/valueparser.h"

using namespace std;

bool ValueParser::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool ValueParser::isWhitespace(char c) {
    return c == ' ' || c == '\t';
}

bool ValueParser::isEndOfLine(char c) {
    return c == '\n' || c == '\r';
}

bool ValueParser::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool ValueParser::tryParseInt(string s, void **val) {
    int cnt = 0;

    for (char c : s)
        if (isDigit(c) == false)
            return false;
        else
            cnt++;

    if (cnt > 9)
        return false;

    *val = new int(stoi(s));

    return true;
}
