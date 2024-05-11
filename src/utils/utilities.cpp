#include "../../headers/utils/utilities.h"

string Utilities::parseSyntaxKind(SyntaxKind kind) {
    switch (kind) {
        case NumberToken:
            return "Number Token";
        case StringToken:
            return "String Token";
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
        case OpenSquareBracketToken:
            return "Open Square Bracket Token";
        case CloseSquareBracketToken:
            return "Close Square Bracket Token";

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
        case CommaToken:
            return "Comma Token";
        case CommentToken:
            return "Comment Token";
        case ContinueToken:
            return "Continue Token";
        case BreakToken:
            return "Break Token";

        case WhiteSpaceToken:
            return "White Space Token";
        case EndOfLineToken:
            return "End Of Line Token";
        case EndOfFileToken:
            return "End Of File Token";

        case Expression:
            return "Expression";
        case CommentExpression:
            return "Comment Expression";
        case InterruptExpression:
            return "Interrupt Expression";
        case PrintExpression:
            return "Print Expression";
        case AssignmentExpression:
            return "Assignment Expression";
        case NameExpression:
            return "Name Expression";
        case LiteralExpression:
            return "Literal Expression";
        case StringExpression:
            return "String Expression";
        case ListExpression:
            return "List Expression";
        case UnaryExpression:
            return "Unary Expression";
        case BinaryExpression:
            return "Binary Expression";
        case ParenthesizedExpression:
            return "Parenthesized Expression";
        case IndexExpression:
            return "Index Expression";

        case Statement:
            return "Statement";
        case IfExpression:
            return "If Expression";
        case IfToken:
            return "If Token";
        case ThenToken:
            return "Then Token";
        case ElseToken:
            return "Else Token";
        case LoopExpression:
            return "Loop Expression";
        case WhileToken:
            return "While Token";
        case ForToken:
            return "For Token";
        case DoToken:
            return "Do Token";
        case PrintToken:
            return "Print Token";
        case ColonToken:
            return "Colon Token";

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
    else if (text == "else")
        return ElseToken;
    else if (text == "while")
        return WhileToken;
    else if (text == "for")
        return ForToken;
    else if (text == "do")
        return DoToken;
    else if (text == "continue")
        return ContinueToken;
    else if (text == "break")
        return BreakToken;
    else if (text == "print")
        return PrintToken;

    else
        return IdentifierToken;
}

void Utilities::print(SyntaxNode *node, string intend, bool isLast) {
    if (node == nullptr) return;
    cout << "\x1B[32m";
    string mark = isLast ? "└── " : "├── ";

    cout << intend << mark << parseSyntaxKind(node->getKind()) << ' ';

    SyntaxToken *token = dynamic_cast<SyntaxToken *>(node);
    if (token)
        tryGetVal(token->getValue());

    cout << '\n';

    intend += isLast ? "    " : "│   ";

    vector<SyntaxNode *> children = node->getChildren();

    for (SyntaxNode *child : children)
        print(child, intend, child == children.back());
    cout << "\x1B[0m";
}

void Utilities::printVal(Value value) {
    if (value.val == nullptr) return;

    switch (value.type) {
        case ValueType::Number:
            cout << *static_cast<int *>(value.val);
            break;
        case ValueType::String:
            cout << *static_cast<string *>(value.val);
            break;
        case ValueType::Boolean:
            cout << ((*static_cast<bool *>(value.val)) ? "true" : "false");
            break;
        case ValueType::List: {
            vector<Value> values = *static_cast<vector<Value> *>(value.val);
            cout << "[ ";
            for (size_t i = 0; i < values.size(); i++) {
                printVal(values[i]);
                if (i != values.size() - 1)
                    cout << ", ";
            }
            cout << " ]";
            break;
        }
        default:
            break;
    }
}

void Utilities::tryGetVal(Value value) {
    if (value.val == nullptr) return;
    cout << "Value: ";
    printVal(value);
}

void Utilities::printErrors(ErrorList errors) {
    for (int i = 0; i < errors.size(); i++) {
        Error *err;

        cout << "\x1B[31m";

        err = dynamic_cast<RuntimeError *>(errors[i]);
        if (err)
            cout << err->getMessage() << '\n';

        err = dynamic_cast<IllegalCharacterError *>(errors[i]);
        if (err)
            cout << err->getMessage() << '\n';

        err = dynamic_cast<SyntaxError *>(errors[i]);
        if (err)
            cout << err->getMessage() << '\n';

        cout << "\x1B[0m";
    }
}

void Utilities::printResult(Value result) {
    if (result.val == nullptr) return;
    cout << "\x1B[32m";
    cout << "The result is: ";
    printVal(result);
    cout << "\x1B[0m\n";
}
