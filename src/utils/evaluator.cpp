#include "../../headers/utils/evaluator.h"

Evaluator::Evaluator(ExpressionSyntax *root)
    : mRoot(root) {}

int Evaluator::evaluate() {
    return evaluateExpression(mRoot);
}

int Evaluator::evaluateExpression(ExpressionSyntax *node) {
    LiteralExpressionSyntax *numberExpression = dynamic_cast<LiteralExpressionSyntax *>(node);
    if (numberExpression) {
        return *numberExpression->getNumberToken()->getValue().pInt;
    }

    UnaryExpressionSyntax *unaryExpression = dynamic_cast<UnaryExpressionSyntax *>(node);
    if (unaryExpression) {
        int operand = evaluateExpression(unaryExpression->getOperand());

        if (unaryExpression->getOperator()->getKind() == PlusToken)
            return operand;
        else if (unaryExpression->getOperator()->getKind() == MinusToken)
            return -operand;

        throw runtime_error("Unexpected unary operator " + to_string(unaryExpression->getOperator()->getKind()));
    }

    BinaryExpressionSyntax *binaryExpression = dynamic_cast<BinaryExpressionSyntax *>(node);
    if (binaryExpression) {
        int left = evaluateExpression(binaryExpression->getLeft());
        int right = evaluateExpression(binaryExpression->getRight());

        switch (binaryExpression->getOperator()->getKind()) {
            case PlusToken:
                return left + right;
            case MinusToken:
                return left - right;
            case StarToken:
                return left * right;
            case SlashToken:
                return left / right;
            default:
                throw runtime_error("Unexpected binary operator");
        }
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression)
        return evaluateExpression(parenthesizedExpression->getExpression());

    throw runtime_error("Unexpected node");
}
