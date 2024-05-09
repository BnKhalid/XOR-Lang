#include "../../headers/utils/indexexpressionsyntax.h"

IndexExpressionSyntax::IndexExpressionSyntax(ExpressionSyntax *Iteratable, SyntaxToken *openSquareBrackets, ExpressionSyntax *index, SyntaxToken *closequareBrackets)
    : mIteratable(Iteratable)
    , mOpenSquareBrackets(openSquareBrackets)
    , mIndex(index)
    , mCloseSquareBrackets(closequareBrackets) {}

SyntaxKind IndexExpressionSyntax::getKind() {
    return SyntaxKind::IndexExpression;
}

vector<SyntaxNode *> IndexExpressionSyntax::getChildren() {
    vector<SyntaxNode *> children;
    children.push_back(mIteratable);
    children.push_back(mOpenSquareBrackets);
    children.push_back(mIndex);
    children.push_back(mCloseSquareBrackets);

    return children;
}

ExpressionSyntax *IndexExpressionSyntax::getIteratable() {
    return mIteratable;
}

SyntaxToken *IndexExpressionSyntax::getOpenSquareBrackets() {
    return mOpenSquareBrackets;
}

ExpressionSyntax *IndexExpressionSyntax::getIndex() {
    return mIndex;
}

SyntaxToken *IndexExpressionSyntax::getCloseSquareBrackets() {
    return mCloseSquareBrackets;
}
