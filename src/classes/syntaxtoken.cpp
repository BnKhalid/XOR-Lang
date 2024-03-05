#include <iostream>
#include "../../headers/classes/syntaxtoken.h"

using namespace std;

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text, Value val)
    : mKind(kind)
    , mPosition(position)
    , mText(text)
    , mVal(val) {}

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text)
    : mKind(kind)
    , mPosition(position)
    , mText(text) {}

void SyntaxToken::print() {
    cout << "'" << mText << "' ";
    cout << "at " << mPosition << " ";
    cout << "with kind " << printSyntaxKind(mKind) << " ";
    printValue();
    cout << '\n';
}

SyntaxKind SyntaxToken::getKind() {
    return mKind;
}

int SyntaxToken::getPosition() {
    return mPosition;
}

string SyntaxToken::getText() {
    return mText;
}

Value SyntaxToken::getValue() {
    return mVal;
}

void SyntaxToken::printValue() {
    if (mVal.pInt != nullptr)
        return void(cout << "Value: " << *mVal.pInt);
    if (mVal.pDouble != nullptr)
        return void(cout << "Value: " << *mVal.pDouble);
    if (mVal.pChar != nullptr)
        return void(cout << "Value: " << *mVal.pChar);
    if (mVal.pString != nullptr)
        return void(cout << "Value: " << *mVal.pString);
}

string SyntaxToken::printSyntaxKind(SyntaxKind kind) {
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

