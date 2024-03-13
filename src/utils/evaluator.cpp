#include <stdexcept>
#include "../../headers/utils/evaluator.h"
#include "../../headers/utils/numberexpressionsyntax.h"
#include "../../headers/utils/binaryexpressionsyntax.h"
#include "../../headers/utils/parenthesizedexpressionsyntax.h"

Evaluator::Evaluator(ExpressionSyntax *root)
    : mRoot(root) {}

int Evaluator::evaluate() {
    return evaluateExpression(mRoot);
}

int Evaluator::evaluateExpression(ExpressionSyntax *node) {
    NumberExpressionSyntax *numberExpression = dynamic_cast<NumberExpressionSyntax *>(node);
    if (numberExpression)
        return *numberExpression->getNumberToken()->getValue().pInt;

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

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression)
        return evaluateExpression(parenthesizedExpression->getExpression());

    throw runtime_error("Unexpected node");
}
