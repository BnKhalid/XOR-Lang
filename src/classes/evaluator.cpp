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
        else if (ifExpressionSyntax->getElseStatment() != nullptr)
            return evaluateStatement(ifExpressionSyntax->getElseStatment());

        vector<string> deletedVariables;
        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                deletedVariables.push_back(key);
        }

        for (auto key : deletedVariables)
            mVariables->erase(key);

        return Value(new bool(1), ValueType::Boolean);
    }

    ForExpressionSyntax *forExpressionSyntax = dynamic_cast<ForExpressionSyntax *>(node);
    if (forExpressionSyntax) {
        int *pCount = static_cast<int *>(evaluateExpression(forExpressionSyntax->getCount()).val);
        if (pCount == nullptr)
            return {};

        int count = *pCount;
        string name = forExpressionSyntax->getIdentifier()->getIdentifierToken()->getText();

        map<string, Value> variablesSnapshot = *mVariables;

        int *pValue = new int(0);
        (*mVariables)[name] = Value(pValue, ValueType::Number);
        while ((*pValue) < count) {
            Value result = evaluateStatement(forExpressionSyntax->getStatment());

            if (result.val == nullptr)
                return {};

            if (result.type == ValueType::BreakType)
                break;

            (*pValue)++;

            if (result.type == ValueType::ContinueType)
                continue;
        }

        vector<string> deletedVariables;
        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                deletedVariables.push_back(key);
        }

        for (auto key : deletedVariables)
            mVariables->erase(key);

        return Value(new bool(1), ValueType::Boolean);
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

            pCondition = static_cast<bool *>(evaluateExpression(whileExpressionSyntax->getCondition()).val);
            if (pCondition == nullptr)
                return {};

            condition = *pCondition;

            if (result.val == nullptr)
                return {};
            if (result.type == ValueType::BreakType)
                break;
            if (result.type == ValueType::ContinueType)
                continue;
        }

        vector<string> deletedVariables;
        for (auto [key, val] : *mVariables) {
            if (variablesSnapshot.find(key) == variablesSnapshot.end())
                deletedVariables.push_back(key);
        }

        for (auto key : deletedVariables)
            mVariables->erase(key);

        return Value(new bool(1), ValueType::Boolean);
    }

    PrintExpressionSyntax *printExpressionSyntax = dynamic_cast<PrintExpressionSyntax *>(node);
    if (printExpressionSyntax) {
        Value value = evaluateExpression(printExpressionSyntax->getExpression());
        if (value.val == nullptr)
            return {};

        Utilities::printVal(value);
        cout << "\n\n";
        return value;
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

    ListExpressionSyntax *listExpression = dynamic_cast<ListExpressionSyntax *>(node);
    if (listExpression) {
        vector<Value> values;
        for (auto expression : listExpression->getListObjects()) {
            Value value = evaluateExpression(expression);
            if (value.val == nullptr)
                return {};
            values.push_back(value);
        }

        return Value(new vector<Value>(values), ValueType::List);
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

        else if (lValue.type == ValueType::Boolean && rValue.type == ValueType::Boolean) {
            bool left = *static_cast<bool *>(lValue.val);
            bool right = *static_cast<bool *>(rValue.val);

            SyntaxToken *operatorToken = binaryExpression->getOperator();
            switch (operatorToken->getKind()) {
                case AmpersandAmpersandToken:
                    return Value(new bool(left && right), ValueType::Boolean);
                case PipePipeToken:
                    return Value(new bool(left || right), ValueType::Boolean);
                case EqualEqualToken:
                    return Value(new bool(left == right), ValueType::Boolean);
                case BangEqualToken:
                    return Value(new bool(left != right), ValueType::Boolean);
                default:
                    mErrors->throwError(new RuntimeError(operatorToken->getText(), RuntimeErrorType::INVALID_OPERATOR));
                    return {};
            }

            return {};
        }

        else if (lValue.type == ValueType::List && rValue.type == ValueType::List) {
            vector<Value> left = *static_cast<vector<Value> *>(lValue.val);
            vector<Value> right = *static_cast<vector<Value> *>(rValue.val);

            SyntaxToken *operatorToken = binaryExpression->getOperator();
            switch (operatorToken->getKind()) {
                case PlusToken: {
                    left.insert(left.end(), right.begin(), right.end());
                    return Value(new vector<Value>(left), ValueType::List);
                }
                default:
                    mErrors->throwError(new RuntimeError(operatorToken->getText(), RuntimeErrorType::INVALID_OPERATOR));
                    return {};
            }

            return {};
        }

        mErrors->throwError(new RuntimeError("Binary", RuntimeErrorType::INVALID_EXPRESSION));
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression) {
        Value result = evaluateExpression(parenthesizedExpression->getExpression());
        return result;
    }

    InterruptExpressionSyntax *interruptExpression = dynamic_cast<InterruptExpressionSyntax *>(node);
    if (interruptExpression) {
        switch (interruptExpression->getInterruptToken()->getKind()) {
            case ContinueToken:
                return Value(new bool(1), ValueType::ContinueType);
            case BreakToken:
                return Value(new bool(1), ValueType::BreakType);
            default:
                return {};
        }
    }

    CommentExpressionSyntax *commentExpression = dynamic_cast<CommentExpressionSyntax *>(node);
    if (commentExpression) {
        return Value(new bool(1), ValueType::Boolean);
    }

    return {};
}
