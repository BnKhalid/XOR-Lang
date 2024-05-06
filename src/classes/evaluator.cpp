#include "../../headers/classes/evaluator.h"

Evaluator::Evaluator(ExpressionSyntax *root, map<string, void *> *variables, ErrorList *errors)
    : mRoot(root)
    , mVariables(variables)
    , mErrors(errors) {}

void *Evaluator::evaluate() {
    if (!mErrors->empty() || mRoot == nullptr)
        return nullptr;
    return evaluateStatement(mRoot);
}

void *Evaluator::evaluateStatement(ExpressionSyntax *node) {
    IfExpressionSyntax *ifExpressionSyntax = dynamic_cast<IfExpressionSyntax *>(node);
    if (ifExpressionSyntax) {
        int *pCondition = static_cast<int *>(evaluateExpression(ifExpressionSyntax->getCondition()));
        if (pCondition == nullptr)
            return nullptr;

        int condition = *pCondition;
        if (condition)
            return evaluateStatement(ifExpressionSyntax->getStatment());

        return nullptr;
    }

    return evaluateExpression(node);
}

void *Evaluator::evaluateExpression(ExpressionSyntax *node) {
    LiteralExpressionSyntax *literalExpression = dynamic_cast<LiteralExpressionSyntax *>(node);
    if (literalExpression) {
        int val = *static_cast<int *>(literalExpression->getValue());
        return new int(val);
    }

    NameExpressionSyntax *nameExpression = dynamic_cast<NameExpressionSyntax *>(node);
    if (nameExpression) {
        string name = nameExpression->getIdentifierToken()->getText();
        if (mVariables->find(name) == mVariables->end()) {
            mErrors->throwError(new RuntimeError(name, RuntimeErrorType::UNDEFINED_VARIABLE));
            return nullptr;
        }

        return static_cast<int *>((*mVariables)[name]);
    }

    AssignmentExpressionSyntax *assignmentExpression = dynamic_cast<AssignmentExpressionSyntax *>(node);
    if (assignmentExpression) {
        string name = assignmentExpression->getIdentifierToken()->getText();
        void *value = evaluateExpression(assignmentExpression->getExpression());

        if (value == nullptr)
            return nullptr;

        (*mVariables)[name] = value;
        return value;
    }

    UnaryExpressionSyntax *unaryExpression = dynamic_cast<UnaryExpressionSyntax *>(node);
    if (unaryExpression) {
        int *pOperand = static_cast<int *>(evaluateExpression(unaryExpression->getOperand()));
        if (pOperand == nullptr)
            return nullptr;

        int operand = *pOperand;
        if (unaryExpression->getOperator()->getKind() == PlusToken)
            return new int(operand);
        else if (unaryExpression->getOperator()->getKind() == MinusToken)
            return new int(-operand);
        else if (unaryExpression->getOperator()->getKind() == BangToken)
            return new int(!operand);

        throw runtime_error("Unexpected unary operator " + to_string(unaryExpression->getOperator()->getKind()));
    }

    BinaryExpressionSyntax *binaryExpression = dynamic_cast<BinaryExpressionSyntax *>(node);
    if (binaryExpression) {
        int *pLeft = static_cast<int *>(evaluateExpression(binaryExpression->getLeft()));
        int *pRight = static_cast<int *>(evaluateExpression(binaryExpression->getRight()));

        if (pLeft == nullptr || pRight == nullptr)
            return nullptr;

        int left = *pLeft;
        int right = *pRight;

        switch (binaryExpression->getOperator()->getKind()) {
            case PlusToken:
                return new int(left + right);
            case MinusToken:
                return new int(left - right);
            case StarToken:
                return new int(left * right);
            case SlashToken: {
                if (right == 0) {
                    mErrors->throwError(new RuntimeError("", RuntimeErrorType::DIVISION_BY_ZERO));
                    return nullptr;
                }
                return new int(left / right);
            }
            case AmpersandAmpersandToken:
                return new int(left && right);
            case PipePipeToken:
                return new int(left || right);
            case EqualEqualToken:
                return new int(left == right);
            case BangEqualToken:
                return new int(left != right);
            case BiggerToken:
                return new int(left > right);
            case SmallerToken:
                return new int(left < right);
            case BiggerEqualToken:
                return new int(left >= right);
            case SmallerEqualToken:
                return new int(left <= right);
            default:
                throw runtime_error("Unexpected binary operator");
        }
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression)
        return evaluateExpression(parenthesizedExpression->getExpression());

    throw runtime_error("Unexpected node");
}
