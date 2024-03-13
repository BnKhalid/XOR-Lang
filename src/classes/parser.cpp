#include "../../headers/classes/parser.h"
#include "../../headers/utils/utilities.h"

Parser::Parser(string line) {
    Lexer lex(line);

    while (true) {
        mTokens.push_back(lex.nextToken());

        if (mTokens.back().getKind() == WhiteSpaceToken)
            mTokens.pop_back();

        if (mTokens.back().getKind() == EndOfFileToken)
            break;
    }

    mDiagnostics = lex.getDiagnostics();
}

SyntaxTree *Parser::parse() {
    ExpressionSyntax *expression = parseTerm();
    SyntaxToken endOfFileToken = *match(EndOfFileToken);

    return new SyntaxTree(mDiagnostics, expression, endOfFileToken);
}

ExpressionSyntax *Parser::parseTerm() {
    ExpressionSyntax *left = parseFactor();

    while (current()->getKind() == PlusToken || current()->getKind() == MinusToken) {
        SyntaxToken *operatorToken = nextToken();

        ExpressionSyntax *right = parseFactor();

        left = new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
}

ExpressionSyntax *Parser::parseFactor() {
    ExpressionSyntax *left = parsePrimaryExpression();

    while (current()->getKind() == StarToken || current()->getKind() == SlashToken) {
        SyntaxToken *operatorToken = nextToken();

        ExpressionSyntax *right = parsePrimaryExpression();

        left = new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
}

SyntaxToken *Parser::peek(int offset) {
    size_t index = mPosition + offset;

    if (index >= mTokens.size())
        return &mTokens.back();

    return &mTokens[index];
}

SyntaxToken *Parser::current() {
    return peek(0);
}

SyntaxToken *Parser::nextToken() {
    SyntaxToken *currentToken = current();
    mPosition++;

    return currentToken;
}

SyntaxToken *Parser::match(SyntaxKind kind) {
    if (current()->getKind() == kind)
        return nextToken();

    mDiagnostics.push_back(
        "ERROR: UNEXPECTED token "
        + Utilities::printSyntaxKind(current()->getKind())
        + ", EXPECTED "
        + Utilities::printSyntaxKind(kind)
    );
    return new SyntaxToken(BadToken, mPosition, "");
}

ExpressionSyntax *Parser::parsePrimaryExpression() {
    if (current()->getKind() == OpenParenthesisToken) {
        SyntaxToken *left = match(OpenParenthesisToken);
        ExpressionSyntax *expression = parseTerm();
        SyntaxToken *right = match(CloseParenthesisToken);

        return new ParenthesizedExpressionSyntax(left, expression, right);
    }

    SyntaxToken *token = match(NumberToken);

    return new NumberExpressionSyntax(token);
}

vector<string> Parser::getDiagnostics() {
    return mDiagnostics;
}
