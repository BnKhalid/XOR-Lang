#include "../../headers/utils/syntaxtree.h"

SyntaxTree::SyntaxTree(vector<string> diagnostics, ExpressionSyntax *root, SyntaxToken endOfFileToken)
    : mDiagnostics(diagnostics)
    , mRoot(root)
    , mEndOfFileToken(endOfFileToken) {}

vector<string> SyntaxTree::getDiagnostics() {
    return mDiagnostics;
}

ExpressionSyntax *SyntaxTree::getRoot() {
    return mRoot;
}

SyntaxToken SyntaxTree::getEndOfFileToken() {
    return mEndOfFileToken;
}
