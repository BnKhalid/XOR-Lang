#include "../../headers/classes/evaluator.h"

Evaluator::Evaluator(ExpressionSyntax *root, map<string, Value> *variables, ErrorList *errors)
    : mRoot(root)
    , mVariables(variables)
    , mErrors(errors) {}

Value Evaluator::evaluate() {
    if (!mErrors->empty() || mRoot == nullptr)
        return {};
    return evaluateStatement(mRoot);
}

Value Evaluator::evaluateStatement(ExpressionSyntax *node) {
    IfExpressionSyntax *ifExpressionSyntax = dynamic_cast<IfExpressionSyntax *>(node);
    if (ifExpressionSyntax) {
        bool *pCondition = static_cast<bool *>(evaluateExpression(ifExpressionSyntax->getCondition()).val);
        if (pCondition == nullptr)
            return {};

        map<string, Value> variablesSnapshot = *mVariables;
        
        bool condition = *pCondition;
        if (condition)
            return evaluateStatement(ifExpressionSyntax->getStatment());

        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                mVariables->erase(key);
        }

        return {};
    }

    ForExpressionSyntax *forExpressionSyntax = dynamic_cast<ForExpressionSyntax *>(node);
    if (forExpressionSyntax) {
        int *pCount = static_cast<int *>(evaluateExpression(forExpressionSyntax->getCount()).val);
        if (pCount == nullptr)
            return {};

        int count = *pCount;
        string name = forExpressionSyntax->getIdentifier()->getIdentifierToken()->getText();

        map<string, Value> variablesSnapshot = *mVariables;

        (*mVariables)[name] = Value(new int(0), ValueType::Number);
        while (*static_cast<int *>(((*mVariables)[name]).val) < count) {
            Value result = evaluateStatement(forExpressionSyntax->getStatment());

            if (result.val == nullptr)
                return {};

            (*static_cast<int *>(((*mVariables)[name]).val))++;
        }

        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                mVariables->erase(key);
        }

        return Value(new int(1), ValueType::Number);
    }

    WhileExpressionSyntax *whileExpressionSyntax = dynamic_cast<WhileExpressionSyntax *>(node);
    if (whileExpressionSyntax) {
        bool *pCondition = static_cast<bool *>(evaluateExpression(whileExpressionSyntax->getCondition()).val);
        if (pCondition == nullptr)
            return {};

        map<string, Value> variablesSnapshot = *mVariables;

        bool condition = *pCondition;
        while (condition) {
            Value result = evaluateStatement(whileExpressionSyntax->getStatment());

            if (result.val == nullptr)
                return {};

            pCondition = static_cast<bool *>(evaluateExpression(whileExpressionSyntax->getCondition()).val);
            if (pCondition == nullptr)
                return {};

            condition = *pCondition;
        }

        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                mVariables->erase(key);
        }

        return Value(new bool(1), ValueType::Boolean);
    }

    return evaluateExpression(node);
}

Value Evaluator::evaluateExpression(ExpressionSyntax *node) {
    LiteralExpressionSyntax *literalExpression = dynamic_cast<LiteralExpressionSyntax *>(node);
    if (literalExpression) {
        Value val = literalExpression->getValue();
        return val;
    }

    StringExpressionSyntax *stringExpression = dynamic_cast<StringExpressionSyntax *>(node);
    if (stringExpression) {
        Value val = stringExpression->getValue();
        return val;
    }

    NameExpressionSyntax *nameExpression = dynamic_cast<NameExpressionSyntax *>(node);
    if (nameExpression) {
        string name = nameExpression->getIdentifierToken()->getText();
        if (mVariables->find(name) == mVariables->end()) {
            mErrors->throwError(new RuntimeError(name, RuntimeErrorType::UNDEFINED_VARIABLE));
            return {};
        }
        Value value = (*mVariables)[name];

        return value;
    }

    AssignmentExpressionSyntax *assignmentExpression = dynamic_cast<AssignmentExpressionSyntax *>(node);
    if (assignmentExpression) {
        string name = assignmentExpression->getIdentifierToken()->getIdentifierToken()->getText();
        Value value = evaluateExpression(assignmentExpression->getExpression());

        if (value.val == nullptr)
            return {};

        (*mVariables)[name] = value;
        return value;
    }

    UnaryExpressionSyntax *unaryExpression = dynamic_cast<UnaryExpressionSyntax *>(node);
    if (unaryExpression) {
        Value result = evaluateExpression(unaryExpression->getOperand());
        if (result.val == nullptr || result.type != ValueType::Number)
            return {};

        int operand = *static_cast<int *>(result.val);
        if (unaryExpression->getOperator()->getKind() == PlusToken)
            return Value(new int(operand), ValueType::Number);
        else if (unaryExpression->getOperator()->getKind() == MinusToken)
            return Value(new int(-operand), ValueType::Number);
        else if (unaryExpression->getOperator()->getKind() == BangToken)
            return Value(new bool(!operand), ValueType::Boolean);

        return {};
    }

    BinaryExpressionSyntax *binaryExpression = dynamic_cast<BinaryExpressionSyntax *>(node);
    if (binaryExpression) {
        auto lValue = evaluateExpression(binaryExpression->getLeft());
        auto rValue = evaluateExpression(binaryExpression->getRight());

        if (lValue.type == ValueType::String && rValue.type == ValueType::String) {
            string left = *static_cast<string *>(lValue.val);
            string right = *static_cast<string *>(rValue.val);

            SyntaxToken *operatorToken = binaryExpression->getOperator();

            switch (operatorToken->getKind()) {
                case PlusToken:
                    return Value(new string(left + right), ValueType::String);
                case EqualEqualToken:
                    return Value(new bool(left == right), ValueType::Boolean);
                case BangEqualToken:
                    return Value(new bool(left != right), ValueType::Boolean);
                case BiggerToken:
                    return Value(new bool(left > right), ValueType::Boolean);
                case SmallerToken:
                    return Value(new bool(left < right), ValueType::Boolean);
                case BiggerEqualToken:
                    return Value(new bool(left >= right), ValueType::Boolean);
                case SmallerEqualToken:
                    return Value(new bool(left <= right), ValueType::Boolean);
                default:
                    mErrors->throwError(new RuntimeError(operatorToken->getText(), RuntimeErrorType::INVALID_OPERATOR));
                    return {};
            }

            return {};
        }

        else if (lValue.type == ValueType::Number && rValue.type == ValueType::Number) {
            int left = *static_cast<int *>(lValue.val);
            int right = *static_cast<int *>(rValue.val);

            SyntaxToken *operatorToken = binaryExpression->getOperator();
            switch (operatorToken->getKind()) {
                case PlusToken:
                    return Value(new int(left + right), ValueType::Number);
                case MinusToken:
                    return Value(new int(left - right), ValueType::Number);
                case StarToken:
                    return Value(new int(left * right), ValueType::Number);
                case SlashToken: {
                    if (right == 0) {
                        mErrors->throwError(new RuntimeError("", RuntimeErrorType::DIVISION_BY_ZERO));
                        return {};
                    }
                    return Value(new int(left / right), ValueType::Number);
                }
                case AmpersandAmpersandToken:
                    return Value(new bool(left && right), ValueType::Boolean);
                case PipePipeToken:
                    return Value(new bool(left || right), ValueType::Boolean);
                case EqualEqualToken:
                    return Value(new bool(left == right), ValueType::Boolean);
                case BangEqualToken:
                    return Value(new bool(left != right), ValueType::Boolean);
                case BiggerToken:
                    return Value(new bool(left > right), ValueType::Boolean);
                case SmallerToken:
                    return Value(new bool(left < right), ValueType::Boolean);
                case BiggerEqualToken:
                    return Value(new bool(left >= right), ValueType::Boolean);
                case SmallerEqualToken:
                    return Value(new bool(left <= right), ValueType::Boolean);
                default:
                    mErrors->throwError(new RuntimeError(operatorToken->getText(), RuntimeErrorType::INVALID_OPERATOR));
                    return {};
            }

            return {};
        }

        return {};
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression) {
        Value result = evaluateExpression(parenthesizedExpression->getExpression());
        return result;
    }

    return {};
}
