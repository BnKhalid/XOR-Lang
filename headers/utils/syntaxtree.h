#pragma once

#include "expressionsyntax.h"
#include "syntaxtoken.h"

class SyntaxTree {
public:
    SyntaxTree(vector<string> diagnostics, ExpressionSyntax *root, SyntaxToken endOfFileToken);

    vector<string> getDiagnostics();

    ExpressionSyntax *getRoot();

    SyntaxToken getEndOfFileToken();

private:
    vector<string> mDiagnostics;
    ExpressionSyntax *mRoot;
    SyntaxToken mEndOfFileToken;
};
