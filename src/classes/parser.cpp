#include "../../headers/classes/parser.h"

Parser::Parser(string line, map<string, void *> *variables) {
    mVariables = variables;
    Lexer lex(line, mVariables);

    while (true) {
        mTokens.push_back(lex.lex());

        if (mTokens.back().getKind() == WhiteSpaceToken)
            mTokens.pop_back();

        if (mTokens.back().getKind() == EndOfLineToken)
            break;
    }

    mErrors = lex.getErrors();
}

SyntaxTree *Parser::parse() {
    if (!mErrors.empty())
        return new SyntaxTree(mErrors, nullptr, SyntaxToken(EndOfLineToken, mPosition, ""));

    ExpressionSyntax *expression = parseExpression();
    SyntaxToken endOfLineToken = *match(EndOfLineToken);

    return new SyntaxTree(mErrors, expression, endOfLineToken);
}

ExpressionSyntax *Parser::parseExpression(int parentPrecedence) {
    if (peek(0)->getKind() == IdentifierToken && peek(1)->getKind() == EqualToken) {
        SyntaxToken *identifierToken = nextToken();
        SyntaxToken *operatorToken = nextToken();
        ExpressionSyntax *right = parseExpression();

        return new AssignmentExpressionSyntax(identifierToken, operatorToken, right);
    }

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
        case BangToken:
            return 5;
        default:
            return 0;
    }
}

int Parser::getBinaryOperatorPrecedence(SyntaxKind kind) {
    switch (kind) {
        case StarToken:
        case SlashToken:
            return 4;
        case PlusToken:
        case MinusToken:
            return 3;
        case EqualEqualToken:
        case BangEqualToken:
            return 2;
        case BiggerToken:
        case SmallerToken:
        case BiggerEqualToken:
        case SmallerEqualToken:
        case AmpersandAmpersandToken:
        case PipePipeToken:
            return 1;
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

    mErrors.throwError(new SyntaxError(kind, current()->getKind()));

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
        case TrueToken:
        case FalseToken: {
            SyntaxToken *token = nextToken();
            return new LiteralExpressionSyntax(token);
        }
        case NumberToken: {
            SyntaxToken *token = match(NumberToken);
            return new LiteralExpressionSyntax(token);
        }
        case IdentifierToken: {
            SyntaxToken *token = match(IdentifierToken);
            return new NameExpressionSyntax(token);
        }
        default: {
            mErrors.throwError(new SyntaxError(Expression, current()->getKind()));
            return new LiteralExpressionSyntax(new SyntaxToken(BadToken, mPosition, ""));
        }
    }
}

ErrorList Parser::getErrors() {
    return mErrors;
}
