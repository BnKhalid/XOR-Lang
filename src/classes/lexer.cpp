#include "../../headers/classes/lexer.h"

Lexer::Lexer(string line, map<string, void *> *variables)
    : mLine(line)
    , position(0)
    , mVariables(variables) {}

SyntaxToken Lexer::lex() {
    if (position >= (int)mLine.length())
        return SyntaxToken(EndOfLineToken, position, "\0");

    if (ValueParser::isDigit(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isDigit(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);

        if (ValueParser::isLetter(current())) {
            mErrors.throwError(new IlligalCharacterError(string(1, current())));
            return SyntaxToken(BadToken, nextPos(), text);
        }

        void *val;
        if (ValueParser::tryParseInt(text, &val))
            return SyntaxToken(NumberToken, start, text, val);
        
        mErrors.throwError(new RuntimeError(text, RuntimeErrorType::OVERFLOW));
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
    else if (ValueParser::isLetter(current())) {
        int start = position;

        while (position < (int)mLine.length() && ValueParser::isLetter(current()))
            nextPos();

        int length = position - start;
        string text = mLine.substr(start, length);
        SyntaxKind kind = Utilities::getKind(text);

        if (kind == TrueToken || kind == FalseToken)
            return SyntaxToken(kind, start, text, new int(kind == TrueToken));
        else if (kind == IdentifierToken && mVariables->find(text) != mVariables->end())
            return SyntaxToken(IdentifierToken, start, text, mVariables->at(text));
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
    else if (current() == ':')
        return SyntaxToken(ColonToken, nextPos(), ":");
    else if (current() == '&' && lookAhead() == '&') {
        nextPos();
        return SyntaxToken(AmpersandAmpersandToken, nextPos(), "&&");
    }
    else if (current() == '|' && lookAhead() == '|') {
        nextPos();
        return SyntaxToken(PipePipeToken, nextPos(), "||");
    }
    else if (current() == '=' && lookAhead() == '=') {
        nextPos();
        return SyntaxToken(EqualEqualToken, nextPos(), "==");
    }
    else if (current() == '=')
        return SyntaxToken(EqualToken, nextPos(), "=");
    else if (current() == '!' && lookAhead() == '=') {
        nextPos();
        return SyntaxToken(BangEqualToken, nextPos(), "!=");
    }
    else if (current() == '!')
        return SyntaxToken(BangToken, nextPos(), "!");
    else if (current() == '>' && lookAhead() == '=') {
        nextPos();
        return SyntaxToken(BiggerEqualToken, nextPos(), ">=");
    }
    else if (current() == '<' && lookAhead() == '=') {
        nextPos();
        return SyntaxToken(SmallerEqualToken, nextPos(), "<=");
    }
    else if (current() == '>')
        return SyntaxToken(BiggerToken, nextPos(), ">");
    else if (current() == '<')
        return SyntaxToken(SmallerToken, nextPos(), "<");

    string text = mLine.substr(position, 1);
    mErrors.throwError(new IlligalCharacterError(text));

    return SyntaxToken(BadToken, nextPos(), text);
}

ErrorList Lexer::getErrors() {
    return mErrors;
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
