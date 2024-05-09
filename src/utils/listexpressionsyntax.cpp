#include "../../headers/utils/listexpressionsyntax.h"

ListExpressionSyntax::ListExpressionSyntax(SyntaxToken *openSquareBrackets, vector<ExpressionSyntax *> listObjects, SyntaxToken *closequareBrackets)
    : mOpenSquareBrackets(openSquareBrackets)
    , mListObjects(listObjects)
    , mCloseSquareBrackets(closequareBrackets) {}

SyntaxKind ListExpressionSyntax::getKind() {
    return ListExpression;
}

vector<SyntaxNode *> ListExpressionSyntax::getChildren() {
    vector<SyntaxNode *> childeren;

    childeren.push_back(mOpenSquareBrackets);
    for (auto &object : mListObjects)
        childeren.push_back(object);
    childeren.push_back(mCloseSquareBrackets);

    return childeren;
}

SyntaxToken *ListExpressionSyntax::getOpenSquareBrackets() {
    return mOpenSquareBrackets;
}

vector<ExpressionSyntax *> ListExpressionSyntax::getListObjects() {
    return mListObjects;
}

SyntaxToken *ListExpressionSyntax::getCloseSquareBrackets() {
    return mCloseSquareBrackets;
}
