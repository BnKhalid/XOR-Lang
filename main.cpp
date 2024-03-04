#include <iostream>

using namespace std;

enum syntaxKind {
    NumberToken,
    WhiteSpaceToken,
    PlusToken,
    MinusToken,
    StarToken,
    SlashToken,
    OpenParenthesisToken,
    CloseParenthesisToken,
    EndOfLineToken,
    BadToken
};

struct value {
    int *pInt = nullptr;
    double *pDouble = nullptr;
    char *pChar = nullptr;
    string *pString = nullptr;
};

class parsing {
public:
    static bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    static bool isWhitespace(char c) {
        return c == ' ' || c == '\t';
    }

    static bool isEndOfLine(char c) {
        return c == '\n' || c == '\r';
    }

    static bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    static bool tryParseInt(string s, value &val) {
        for (char c : s)
            if (isDigit(c) == false)
                return false;

        val.pInt = new int;
        *val.pInt = stoi(s);

        return true;
    }
};

class syntaxToken {
public:
    syntaxToken(syntaxKind kind, int position, string text, value val) : mKind(kind), mPosition(position), mText(text), mVal(val) {}
    syntaxToken(syntaxKind kind, int position, string text) : mKind(kind), mPosition(position), mText(text) {}

    void print() {
        cout << "'" << mText << "' ";
        cout << "at " << mPosition << " ";
        cout << "with kind " << printSyntaxKind(mKind) << " ";
        printValue();
        cout << '\n';
    }

    syntaxKind getKind() { return mKind; }
    int getPosition() { return mPosition; }
    string getText() { return mText; }
    value getValue() { return mVal; }

private:
    syntaxKind mKind;
    int mPosition;
    string mText;
    value mVal;

    void printValue() {
        if (mVal.pInt != nullptr)
            return void(cout << "Value: " << *mVal.pInt);
        if (mVal.pDouble != nullptr)
            return void(cout << "Value: " << *mVal.pDouble);
        if (mVal.pChar != nullptr)
            return void(cout << "Value: " << *mVal.pChar);
        if (mVal.pString != nullptr)
            return void(cout << "Value: " << *mVal.pString);
    }

    string printSyntaxKind(syntaxKind kind) {
        switch (kind) {
            case NumberToken:
                return "NumberToken";
            case WhiteSpaceToken:
                return "WhiteSpaceToken";
            case PlusToken:
                return "PlusToken";
            case MinusToken:
                return "MinusToken";
            case StarToken:
                return "StarToken";
            case SlashToken:
                return "SlashToken";
            case OpenParenthesisToken:
                return "OpenParenthesisToken";
            case CloseParenthesisToken:
                return "CloseParenthesisToken";
            case EndOfLineToken:
                return "EndOfLineToken";
            default:
                return "BadToken";
        }
    }
};

class lexer {
public:
    lexer(string line) : mLine(line), position(0) {}

    int updatePosition() {
        return position++;
    }

    syntaxToken nextToken() {
        if (position >= (int)mLine.length())
            return syntaxToken(EndOfLineToken, position, "\0");

        if (parsing::isDigit(mLine[position])) {
            int start = position;

            while (position < (int)mLine.length() && parsing::isDigit(mLine[position]))
                updatePosition();

            int length = position - start;
            string text = mLine.substr(start, length);

            value val;
            if (parsing::tryParseInt(text, val))
                return syntaxToken(NumberToken, start, text, val);
            else
                return syntaxToken(BadToken, start, text);
        }
        else if (parsing::isWhitespace(mLine[position])) {
            int start = position;

            while (position < (int)mLine.length() && parsing::isWhitespace(mLine[position]))
                updatePosition();

            int length = position - start;
            string text = mLine.substr(start, length);

            return syntaxToken(WhiteSpaceToken, start, text);
        }
        else if (mLine[position] == '+')
            return syntaxToken(PlusToken, updatePosition(), "+");
        else if (mLine[position] == '-')
            return syntaxToken(MinusToken, updatePosition(), "-");
        else if (mLine[position] == '*')
            return syntaxToken(StarToken, updatePosition(), "*");
        else if (mLine[position] == '/')
            return syntaxToken(SlashToken, updatePosition(), "/");
        else if (mLine[position] == '(')
            return syntaxToken(OpenParenthesisToken, updatePosition(), "(");
        else if (mLine[position] == ')')
            return syntaxToken(CloseParenthesisToken, updatePosition(), ")");
        else
            return syntaxToken(BadToken, updatePosition(), mLine.substr(position, 1));
    }

private:
    string mLine;
    int position;
};

int main() {
    string line;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line.empty())
            break;

        lexer lex(line);

        while (true) {
            syntaxToken token = lex.nextToken();

            if (token.getKind() == EndOfLineToken)
                break;

            token.print();
        }
    }
    return 0;
}