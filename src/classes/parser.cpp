#include "../../headers/classes/parser.h"

Parser::Parser(string line) {
    Lexer lex(line);

    while (true) {
        mTokens.push_back(lex.nextToken());

        SyntaxKind kind = mTokens.back().getKind();
        if (kind == WhiteSpaceToken || kind == BadToken || kind == EndOfLineToken)
            mTokens.pop_back();

        if (kind == EndOfLineToken)
            break;
    }
}

ExpressionSyntax *Parser::parse() {
    ExpressionSyntax *left = parsePrimaryExpression();

    while (current()->getKind() == PlusToken || current()->getKind() == MinusToken) {
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

    return new SyntaxToken(BadToken, mPosition, "");
}

ExpressionSyntax *Parser::parsePrimaryExpression() {
    if (current()->getKind() == NumberToken) {
        SyntaxToken *numberToken = match(NumberToken);

        return new NumberExpressionSyntax(numberToken);
    }
    return new NumberExpressionSyntax(new SyntaxToken(BadToken, mPosition, ""));
}
