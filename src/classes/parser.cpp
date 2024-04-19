#include "../../headers/classes/parser.h"

Parser::Parser(string line) {
    Lexer lex(line);

    while (true) {
        mTokens.push_back(lex.lex());

        if (mTokens.back().getKind() == WhiteSpaceToken)
            mTokens.pop_back();

        if (mTokens.back().getKind() == EndOfLineToken)
            break;
    }

    mDiagnostics = lex.getDiagnostics();
}

SyntaxTree *Parser::parse() {
    ExpressionSyntax *expression = parseExpression();
    SyntaxToken endOfLineToken = *match(EndOfLineToken);

    return new SyntaxTree(mDiagnostics, expression, endOfLineToken);
}

ExpressionSyntax *Parser::parseExpression(int parentPrecedence) {
    ExpressionSyntax *left;

    int unaryPrecedence = getUnaryOperatorPrecedence(current()->getKind());

    if (unaryPrecedence != 0 && unaryPrecedence >= parentPrecedence) {
        SyntaxToken *operatorToken = nextToken();
        ExpressionSyntax *operand = parseExpression(unaryPrecedence);

        left = new UnaryExpressionSyntax(operatorToken, operand);
    }
    else
        left = parsePrimaryExpression();

    while (true) {
        int BinaryPrecedence = getBinaryOperatorPrecedence(current()->getKind());

        if (BinaryPrecedence == 0 || BinaryPrecedence <= parentPrecedence)
            break;

        SyntaxToken *operatorToken = nextToken();

        ExpressionSyntax *right = parseExpression(BinaryPrecedence);

        left = new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
}

int Parser::getUnaryOperatorPrecedence(SyntaxKind kind) {
    switch (kind) {
        case PlusToken:
        case MinusToken:
            return 3;
        default:
            return 0;
    }
}

int Parser::getBinaryOperatorPrecedence(SyntaxKind kind) {
    switch (kind) {
        case PlusToken:
        case MinusToken:
            return 1;
        case StarToken:
        case SlashToken:
            return 2;
        default:
            return 0;
    }
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
    switch (current()->getKind()) {
        case OpenParenthesisToken: {
            SyntaxToken *left = match(OpenParenthesisToken);
            ExpressionSyntax *expression = parseExpression();
            SyntaxToken *right = match(CloseParenthesisToken);
            return new ParenthesizedExpressionSyntax(left, expression, right);
        }
        case TrueKeywordToken:
        case FalseKeywordToken: {
            SyntaxToken *token = nextToken();
            return new LiteralExpressionSyntax(token);
        }
        case NumberToken: {
            SyntaxToken *token = match(NumberToken);
            return new LiteralExpressionSyntax(token);
        }
        default: {
            mDiagnostics.push_back(
                "ERROR: UNEXPECTED token "
                + Utilities::printSyntaxKind(current()->getKind())
                + ", EXPECTED primary expression"
            );
            return new LiteralExpressionSyntax(new SyntaxToken(BadToken, mPosition, ""));
        }
    }
}

vector<string> Parser::getDiagnostics() {
    return mDiagnostics;
}
