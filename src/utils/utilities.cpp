#include <iostream>
#include "../../headers/utils/utilities.h"

string utilities::printSyntaxKind(SyntaxKind kind) {
    switch (kind) {
        case NumberToken:
            return "NumberToken";
        case WhiteSpaceToken:
            return "WhiteSpaceToken";
        case PlusToken:
            return "PlusToken";
        case MinusToken:
            return "MinusToken";
        case StarToken:
            return "StarToken";
        case SlashToken:
            return "SlashToken";
        case OpenParenthesisToken:
            return "OpenParenthesisToken";
        case CloseParenthesisToken:
            return "CloseParenthesisToken";
        case EndOfLineToken:
            return "EndOfLineToken";
        case NumberExpressionToken:
            return "NumberExpressionToken";
        case BinaryExpressionToken:
            return "BinaryExpressionToken";
        case ExpressionToken:
            return "ExpressionToken";
        default:
            return "BadToken";
    }
}

void utilities::print(SyntaxNode *node, string intend, bool isLast) {
    string mark = isLast ? "└── " : "├── ";

    cout << intend << mark << printSyntaxKind(node->getKind()) << ' ';

    if (dynamic_cast<SyntaxToken *>(node) != nullptr) {
        SyntaxToken *token = static_cast<SyntaxToken *>(node);
        token->printValue();
    }

    cout << '\n';

    intend += isLast ? "    " : "│   ";

    vector<SyntaxNode *> children;

    if (dynamic_cast<BinaryExpressionSyntax *>(node) != nullptr) {
        BinaryExpressionSyntax *binaryExpression = static_cast<BinaryExpressionSyntax *>(node);
        children = binaryExpression->getChildren();
    }
    else if (dynamic_cast<NumberExpressionSyntax *>(node) != nullptr) {
        NumberExpressionSyntax *numberExpression = static_cast<NumberExpressionSyntax *>(node);
        children = numberExpression->getChildren();
    }

    for (size_t i = 0; i < children.size(); i++)
        print(children[i], intend, i == children.size() - 1);
}
