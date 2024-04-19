#include "../../headers/utils/utilities.h"

string Utilities::printSyntaxKind(SyntaxKind kind) {
    switch (kind) {
        case FalseKeywordToken:
            return "False Keyword Token";
        case TrueKeywordToken:
            return "True Keyword Token";
        case IdentifierToken:
            return "Identifier Token";

        case NumberToken:
            return "Number Token";
        case PlusToken:
            return "Plus Token";
        case MinusToken:
            return "Minus Token";
        case StarToken:
            return "Star Token";
        case SlashToken:
            
            return "Slash Token";
        case OpenParenthesisToken:
            return "Open Parenthesis Token";
        case CloseParenthesisToken:
            return "Close Parenthesis Token";

        case WhiteSpaceToken:
            return "White Space Token";
        case EndOfLineToken:
            return "End Of Line Token";
        case EndOfFileToken:
            return "End Of File Token";

        case ExpressionToken:
            return "Expression Token";
        case LiteralExpressionToken:
            return "Literal Expression Token";
        case BinaryExpressionToken:
            return "Binary Expression Token";
        case ParenthesizedExpressionToken:
            return "Parenthesized Expression Token";
        default:
            return "Bad Token";
    }
}

SyntaxKind Utilities::getKind(string text) {
    if (text == "false")
        return FalseKeywordToken;
    else if (text == "true")
        return TrueKeywordToken;
    else
        return IdentifierToken;
}

void Utilities::print(SyntaxNode *node, string intend, bool isLast) {
    string mark = isLast ? "└── " : "├── ";

    cout << intend << mark << printSyntaxKind(node->getKind()) << ' ';

    SyntaxToken *token = dynamic_cast<SyntaxToken *>(node);
    if (token)
        Utilities::printValue(token->getValue());

    cout << '\n';

    intend += isLast ? "    " : "│   ";

    vector<SyntaxNode *> children = node->getChildren();

    for (SyntaxNode *child : children)
        print(child, intend, child == children.back());
}

void Utilities::printValue(void *val) {
    if (val == nullptr) return;
    else if (static_cast<int *>(val))
        cout << "Value: " << *static_cast<int *>(val);
    else if (static_cast<double *>(val))
        cout << "Value: " << *static_cast<double *>(val);
    else if (static_cast<char *>(val))
        cout << "Value: " << *static_cast<char *>(val);
    else if (static_cast<string *>(val))
        cout << "Value: " << *static_cast<string *>(val);
}