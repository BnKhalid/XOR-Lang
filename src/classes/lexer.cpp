#include "../../headers/classes/lexer.h"
#include "../../headers/utils/utilities.h"

Lexer::Lexer(string line)
    : mLine(line)
    , position(0) {}

SyntaxToken Lexer::lex() {
    if (position >= (int)mLine.length())
        return SyntaxToken(EndOfLineToken, position, "\0");

    if (ValueParser::isDigit(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isDigit(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);

        void *val;
        if (ValueParser::tryParseInt(text, &val))
            return SyntaxToken(NumberToken, start, text, val);
        else
            mDiagnostics.push_back("Could not parse number: " + text + " at position " + to_string(start) + " to Int32");
        return SyntaxToken(NumberToken, start, text);
    }
    else if (ValueParser::isWhitespace(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isWhitespace(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);

        return SyntaxToken(WhiteSpaceToken, start, text);
    }
    else if (ValueParser::isLetter(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isLetter(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);
        SyntaxKind kind = Utilities::getKind(text);

        if (kind == TrueKeywordToken || kind == FalseKeywordToken)
            return SyntaxToken(kind, start, text, new int(kind == TrueKeywordToken));
        else
            return SyntaxToken(kind, start, text);
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
    else if (current() == '!')
        return SyntaxToken(BangToken, nextPos(), "!");
    else if (current() == '&' && lookAhead() == '&') {
        nextPos();
        return SyntaxToken(AmpersandAmpersandToken, nextPos(), "&&");
    }
    else if (current() == '|' && lookAhead() == '|') {
        nextPos();
        return SyntaxToken(PipePipeToken, nextPos(), "||");
    }
    
    string text = mLine.substr(position, 1);

    mDiagnostics.push_back("ERROR: Bad character input: " + text);

    return SyntaxToken(BadToken, nextPos(), text);
}

vector<string> Lexer::getDiagnostics() {
    return mDiagnostics;
}

char Lexer::peek(int offset) {
    int index = position + offset;

    if (index >= (int)mLine.length())
        return '\0';

    return mLine[index];
}

char Lexer::current() {
    return peek(0);
}

char Lexer::lookAhead() {
    return peek(1);
}

int Lexer::nextPos() {
    return position++;
}
