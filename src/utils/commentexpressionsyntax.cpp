#include "../../headers/utils/commentexpressionsyntax.h"

CommentExpressionSyntax::CommentExpressionSyntax(SyntaxToken *commentToken)
    : mCommentToken(commentToken) {}

SyntaxKind CommentExpressionSyntax::getKind() {
    return CommentExpression;
}

vector<SyntaxNode *> CommentExpressionSyntax::getChildren() {
    return { mCommentToken };
}

SyntaxToken *CommentExpressionSyntax::getCommentToken() {
    return mCommentToken;
}
