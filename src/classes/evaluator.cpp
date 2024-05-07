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

    ForExpressionSyntax *forExpressionSyntax = dynamic_cast<ForExpressionSyntax *>(node);
    if (forExpressionSyntax) {
        int *pCount = static_cast<int *>(evaluateExpression(forExpressionSyntax->getCount()));
        if (pCount == nullptr)
            return nullptr;

        int count = *pCount;
        string name = forExpressionSyntax->getIdentifier()->getIdentifierToken()->getText();
        bool exists = mVariables->find(name) != mVariables->end();

        if (!exists)
            (*mVariables)[name] = new int(0);
        
        while (*static_cast<int *>((*mVariables)[name]) < count) {
            void *result = evaluateStatement(forExpressionSyntax->getStatment());

            if (result == nullptr)
                return nullptr;

            (*static_cast<int *>((*mVariables)[name]))++;
        }

        if (!exists)
            mVariables->erase(name);

        return new int(1);
    }

    WhileExpressionSyntax *whileExpressionSyntax = dynamic_cast<WhileExpressionSyntax *>(node);
    if (whileExpressionSyntax) {
        int *pCondition = static_cast<int *>(evaluateExpression(whileExpressionSyntax->getCondition()));
        if (pCondition == nullptr)
            return nullptr;

        int condition = *pCondition;
        while (condition) {
            void *result = evaluateStatement(whileExpressionSyntax->getStatment());

            if (result == nullptr)
                return nullptr;

            pCondition = static_cast<int *>(evaluateExpression(whileExpressionSyntax->getCondition()));
            if (pCondition == nullptr)
                return nullptr;

            condition = *pCondition;
        }

        return new int(1);
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
        string name = assignmentExpression->getIdentifierToken()->getIdentifierToken()->getText();
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

        return nullptr;
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
                return nullptr;
        }
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression)
        return evaluateExpression(parenthesizedExpression->getExpression());

    return nullptr;
}
