#include "../../headers/utils/utilities.h"

string Utilities::printSyntaxKind(SyntaxKind kind) {
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
        case EndOfFileToken:
            return "EndOfFileToken";
        case ExpressionToken:
            return "ExpressionToken";
        case LiteralExpressionToken:
            return "LiteralExpressionToken";
        case BinaryExpressionToken:
            return "BinaryExpressionToken";
        case ParenthesizedExpressionToken:
            return "ParenthesizedExpressionToken";
        default:
            return "BadToken";
    }
}

void Utilities::print(SyntaxNode *node, string intend, bool isLast) {
    string mark = isLast ? "└── " : "├── ";

    cout << intend << mark << printSyntaxKind(node->getKind()) << ' ';

    if (dynamic_cast<SyntaxToken *>(node) != nullptr) {
        SyntaxToken *token = static_cast<SyntaxToken *>(node);
        token->printValue();
    }

    cout << '\n';

    intend += isLast ? "    " : "│   ";

    vector<SyntaxNode *> children = node->getChildren();

    for (size_t i = 0; i < children.size(); i++)
        print(children[i], intend, i == children.size() - 1);
}
