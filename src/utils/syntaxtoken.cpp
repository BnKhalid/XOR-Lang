#include "../../headers/utils/syntaxtoken.h"
#include "../../headers/utils/utilities.h"

using namespace std;

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text, Value val)
    : mKind(kind)
    , mPosition(position)
    , mText(text)
    , mVal(val) {}

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, string text)
    : SyntaxToken(kind, position, text, {}) {}

void SyntaxToken::print() {
    cout << "'" << mText << "' ";
    cout << "at " << mPosition << " ";
    // cout << "with kind " << parseSyntaxKind(mKind) << " ";
    Utilities::tryGetVal(mVal);
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

vector<SyntaxNode *> SyntaxToken::getChildren() {
    return vector<SyntaxNode *>();
}
