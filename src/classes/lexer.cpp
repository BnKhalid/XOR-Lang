#include "../../headers/classes/lexer.h"
#include "../../headers/utils/valueparser.h"

Lexer::Lexer(string line)
    : mLine(line)
    , position(0) {}

SyntaxToken Lexer::nextToken() {
    if (position >= (int)mLine.length())
        return SyntaxToken(EndOfLineToken, position, "\0");

    if (ValueParser::isDigit(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isDigit(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);

        Value val;
        if (ValueParser::tryParseInt(text, val))
            return SyntaxToken(NumberToken, start, text, val);
        else
            return SyntaxToken(BadToken, start, text);
    }
    else if (ValueParser::isWhitespace(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isWhitespace(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);

        return SyntaxToken(WhiteSpaceToken, start, text);
    }
    else if (current() == '+')
        return SyntaxToken(PlusToken, nextPos(), "+");
    else if (current() == '-')
        return SyntaxToken(MinusToken, nextPos(), "-");
    else if (current() == '*')
        return SyntaxToken(StarToken, nextPos(), "*");
    else if (current() == '/')
        return SyntaxToken(SlashToken, nextPos(), "/");
    else if (current() == '(')
        return SyntaxToken(OpenParenthesisToken, nextPos(), "(");
    else if (current() == ')')
        return SyntaxToken(CloseParenthesisToken, nextPos(), ")");
    else {
        string text = mLine.substr(position, 1);
        return SyntaxToken(BadToken, nextPos(), text);
    }
}

char Lexer::current() {
    if (position >= (int)mLine.length())
        return '\0';

    return mLine[position];
}

int Lexer::nextPos() {
    return position++;
}

