#include "../../headers/utils/evaluator.h"

Evaluator::Evaluator(ExpressionSyntax *root)
    : mRoot(root) {}

int Evaluator::evaluate() {
    return evaluateExpression(mRoot);
}

int Evaluator::evaluateExpression(ExpressionSyntax *node) {
    NumberExpressionSyntax *numberExpression = dynamic_cast<NumberExpressionSyntax *>(node);
    if (numberExpression) {
        return *numberExpression->getNumberToken()->getValue().pInt;
    }

    BinaryExpressionSyntax *binaryExpression = dynamic_cast<BinaryExpressionSyntax *>(node);
    if (binaryExpression) {
        auto left = evaluateExpression(binaryExpression->getLeft());
        auto right = evaluateExpression(binaryExpression->getRight());

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

    throw runtime_error("Unexpected node");
}
