#include "../../headers/utils/syntaxtoken.h"

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
    // cout << "with kind " << printSyntaxKind(mKind) << " ";
    printValue();
    cout << '\n';
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

vector<SyntaxNode *> SyntaxToken::getChildren() {
    return vector<SyntaxNode *>();
}
