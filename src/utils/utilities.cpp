#include "../../headers/utils/utilities.h"

string Utilities::parseSyntaxKind(SyntaxKind kind) {
    switch (kind) {
        case NumberToken:
            return "Number Token";
        case TrueToken:
            return "True Token";
        case FalseToken:
            return "False Token";
        case IdentifierToken:
            return "Identifier Token";
        case OpenParenthesisToken:
            return "Open Parenthesis Token";
        case CloseParenthesisToken:
            return "Close Parenthesis Token";

        case EqualToken:
            return "Equal Token";
        case PlusToken:
            return "Plus Token";
        case MinusToken:
            return "Minus Token";
        case StarToken:
            return "Star Token";
        case SlashToken:
            return "Slash Token";
        case AmpersandAmpersandToken:
            return "Ampersand Ampersand Token";
        case PipePipeToken:
            return "Pipe Pipe Token";
        case EqualEqualToken:
            return "Equal Equal Token";
        case BangEqualToken:
            return "Bang Equal Token";
        case BiggerToken:
            return "Bigger Token";
        case SmallerToken:
            return "Smaller Token";
        case BiggerEqualToken:
            return "Bigger Equal Token";
        case SmallerEqualToken:
            return "Smaller Equal Token";
        case BangToken:
            return "Bang Token";

        case WhiteSpaceToken:
            return "White Space Token";
        case EndOfLineToken:
            return "End Of Line Token";
        case EndOfFileToken:
            return "End Of File Token";

        case Expression:
            return "Expression";
        case AssignmentExpression:
            return "Assignment Expression";
        case NameExpression:
            return "Name Expression";
        case LiteralExpression:
            return "Literal Expression";
        case UnaryExpression:
            return "Unary Expression";
        case BinaryExpression:
            return "Binary Expression";
        case ParenthesizedExpression:
            return "Parenthesized Expression";

        case Statement:
            return "Statement";
        case IfExpression:
            return "If Expression";
        case IfToken:
            return "If Token";
        case ThenToken:
            return "Then Token";
        default:
            return "Bad Token";
    }
}

SyntaxKind Utilities::getKind(string text) {
    if (text == "false")
        return FalseToken;
    else if (text == "true")
        return TrueToken;
    else if (text == "if")
        return IfToken;
    else if (text == "then")
        return ThenToken;
    else
        return IdentifierToken;
}

void Utilities::print(SyntaxNode *node, string intend, bool isLast) {
    string mark = isLast ? "└── " : "├── ";

    cout << intend << mark << parseSyntaxKind(node->getKind()) << ' ';

    SyntaxToken *token = dynamic_cast<SyntaxToken *>(node);
    if (token)
        printValue(token->getValue());

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

void Utilities::printErrors(ErrorList errors) {
    for (int i = 0; i < errors.size(); i++) {
        Error *err;

        err = dynamic_cast<RuntimeError *>(errors[i]);
        if (err) {
            cout << err->getMessage() << '\n';
            continue;
        }

        err = dynamic_cast<IlligalCharacterError *>(errors[i]);
        if (err) {
            cout << err->getMessage() << '\n';
            continue;
        }

        err = dynamic_cast<SyntaxError *>(errors[i]);
        if (err) {
            cout << err->getMessage() << '\n';
            continue;
        }
    }
}

void Utilities::printResult(void *result) {
    if (result == nullptr) return;
    else if (static_cast<int *>(result))
        cout << "The answer is: " << *static_cast<int *>(result) << '\n';
    else if (static_cast<string *>(result))
        cout << "The answer is: " << *static_cast<string *>(result) << '\n';
}
