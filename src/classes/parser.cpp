#include "../../headers/classes/parser.h"

Parser::Parser(string line, map<string, Value> *variables) {
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
        return new SyntaxTree(mErrors, nullptr, SyntaxToken(EndOfLineToken, 0, ""));

    ExpressionSyntax *expression = parseStatementExpression();

    if (current()->getKind() == CommentToken)
        match(CommentToken);
    
    SyntaxToken endOfLineToken = *match(EndOfLineToken);

    return new SyntaxTree(mErrors, expression, endOfLineToken);
}

ExpressionSyntax *Parser::parseStatementExpression() {
    if (current()->getKind() == IfToken) {
        SyntaxToken *ifToken = match(IfToken);
        ExpressionSyntax *condition = parseAssignmentExpression();
        SyntaxToken *thenToken = match(ThenToken);
        ExpressionSyntax *statment = parseStatementExpression();

        if (current()->getKind() == ElseToken) {
            SyntaxToken *elseToken = match(ElseToken);
            ExpressionSyntax *elseStatment = parseStatementExpression();

            return new IfExpressionSyntax(ifToken, condition, thenToken, statment, elseToken, elseStatment);
        }

        return new IfExpressionSyntax(ifToken, condition, thenToken, statment);
    }

    if (current()->getKind() == ForToken) {
        SyntaxToken *forToken = match(ForToken);
        NameExpressionSyntax *identifierToken = new NameExpressionSyntax(match(IdentifierToken));
        SyntaxToken *colonToken = match(ColonToken);
        ExpressionSyntax *range = parseAssignmentExpression();
        SyntaxToken *doToken = match(DoToken);
        ExpressionSyntax *statment = parseStatementExpression();

        return new ForExpressionSyntax(forToken, identifierToken, colonToken, range, doToken, statment);
    }

    if (current()->getKind() == WhileToken) {
        SyntaxToken *whileToken = match(WhileToken);
        ExpressionSyntax *condition = parseAssignmentExpression();
        SyntaxToken *doToken = match(DoToken);
        ExpressionSyntax *statment = parseStatementExpression();

        return new WhileExpressionSyntax(whileToken, condition, doToken, statment);
    }

    if (current()->getKind() == PrintToken) {
        SyntaxToken *printToken = match(PrintToken);
        SyntaxToken *colonToken = match(ColonToken);
        ExpressionSyntax *expression = parseAssignmentExpression();

        return new PrintExpressionSyntax(printToken, colonToken, expression);
    }

    return parseAssignmentExpression();
}

ExpressionSyntax *Parser::parseAssignmentExpression() {
    if (current()->getKind() == IdentifierToken && peek(1)->getKind() == EqualToken) {
        NameExpressionSyntax *identifierToken = new NameExpressionSyntax(match(IdentifierToken));
        SyntaxToken *operatorToken = match(EqualToken);
        ExpressionSyntax *right = parseAssignmentExpression();

        return new AssignmentExpressionSyntax(identifierToken, operatorToken, right);
    }

    return parseListExpression();
}

ExpressionSyntax *Parser::parseListExpression() {
    ExpressionSyntax *left = parseListTermExpression();

    while (true) {
        if (current()->getKind() != PlusToken)
            break;

        SyntaxToken *operatorToken = nextToken();

        ExpressionSyntax *right = parseListTermExpression();

        left = new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
}

ExpressionSyntax *Parser::parseListTermExpression() {
    if (current()->getKind() != OpenSquareBracketToken)
        return parseExpression();

    SyntaxToken *openToken = match(OpenSquareBracketToken);
    vector<ExpressionSyntax *> expressions;

    ExpressionSyntax *expression = parseListExpression();

    while (true) {
        expressions.push_back(expression);

        if (current()->getKind() == CloseSquareBracketToken
            || match(CommaToken)->getKind() != CommaToken)
            break;

        expression = parseListExpression();
    }

    SyntaxToken *closeToken = match(CloseSquareBracketToken);

    ExpressionSyntax *list = new ListExpressionSyntax(openToken, expressions, closeToken);

    while (current()->getKind() == OpenSquareBracketToken) {
        openToken = match(OpenSquareBracketToken);
        ExpressionSyntax *index = parseExpression();
        closeToken = match(CloseSquareBracketToken);

        list = new IndexExpressionSyntax(list, openToken, index, closeToken);
    }

    return list;
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

    while (current()->getKind() == OpenSquareBracketToken) {
        SyntaxToken *openToken = match(OpenSquareBracketToken);
        ExpressionSyntax *index = parseExpression();
        SyntaxToken *closeToken = match(CloseSquareBracketToken);

        left = new IndexExpressionSyntax(left, openToken, index, closeToken);
    }

    while (true) {
        int BinaryPrecedence = getBinaryOperatorPrecedence(current()->getKind());

        if (BinaryPrecedence == 0 || BinaryPrecedence <= parentPrecedence || peek(1)->getKind() == OpenSquareBracketToken)
            break;

        SyntaxToken *operatorToken = nextToken();

        ExpressionSyntax *right = parseExpression(BinaryPrecedence);

        left = new BinaryExpressionSyntax(left, operatorToken, right);
    }

    return left;
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
        case StringToken: {
            SyntaxToken *token = match(StringToken);
            return new StringExpressionSyntax(token);
        }
        case CommentToken: {
            SyntaxToken *token = match(CommentToken);
            return new CommentExpressionSyntax(token);
        }
        case ContinueToken:
        case BreakToken: {
            SyntaxToken *token = nextToken();
            return new InterruptExpressionSyntax(token);
        }
        default: {
            mErrors.throwError(new SyntaxError(Expression, current()->getKind()));
            return new LiteralExpressionSyntax(new SyntaxToken(BadToken, mPosition, ""));
        }
    }
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

ErrorList Parser::getErrors() {
    return mErrors;
}
