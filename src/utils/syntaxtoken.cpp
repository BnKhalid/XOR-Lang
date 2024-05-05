#include "../../headers/utils/syntaxtoken.h"
#include "../../headers/utils/utilities.h"

using namespace std;

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text, void *val)
    : mKind(kind)
    , mPosition(position)
    , mText(text)
    , mVal(val) {}

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text)
    : SyntaxToken(kind, position, text, nullptr) {}

void SyntaxToken::print() {
    cout << "'" << mText << "' ";
    cout << "at " << mPosition << " ";
    // cout << "with kind " << parseSyntaxKind(mKind) << " ";
    Utilities::printValue(mVal);
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

void *SyntaxToken::getValue() {
    return mVal;
}

vector<SyntaxNode *> SyntaxToken::getChildren() {
    return vector<SyntaxNode *>();
}
