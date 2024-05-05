#include "../../headers/utils/syntaxtree.h"

SyntaxTree::SyntaxTree(ErrorList errors, ExpressionSyntax *root, SyntaxToken endOfFileToken)
    : mErrors(errors)
    , mRoot(root)
    , mEndOfFileToken(endOfFileToken) {}

ErrorList SyntaxTree::getErrors() {
    return mErrors;
}

ExpressionSyntax *SyntaxTree::getRoot() {
    return mRoot;
}

SyntaxToken SyntaxTree::getEndOfFileToken() {
    return mEndOfFileToken;
}
