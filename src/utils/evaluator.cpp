#include "../../headers/utils/evaluator.h"
#include "../../headers/utils/utilities.h"

Evaluator::Evaluator(ExpressionSyntax *root)
    : mRoot(root) {}

int Evaluator::evaluate() {
    return evaluateExpression(mRoot);
}

int Evaluator::evaluateExpression(ExpressionSyntax *node) {
    LiteralExpressionSyntax *literalExpression = dynamic_cast<LiteralExpressionSyntax *>(node);
    if (literalExpression) {
        int val = *static_cast<int *>(literalExpression->getValue());
        return val;
    }

    UnaryExpressionSyntax *unaryExpression = dynamic_cast<UnaryExpressionSyntax *>(node);
    if (unaryExpression) {
        int operand = evaluateExpression(unaryExpression->getOperand());

        if (unaryExpression->getOperator()->getKind() == PlusToken)
            return operand;
        else if (unaryExpression->getOperator()->getKind() == MinusToken)
            return -operand;
        else if (unaryExpression->getOperator()->getKind() == BangToken)
            return !operand;

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
            case AmpersandAmpersandToken:
                return left && right;
            case PipePipeToken:
                return left || right;
            case EqualEqualToken:
                return left == right;
            case BangEqualToken:
                return left != right;
            case BiggerToken:
                return left > right;
            case SmallerToken:
                return left < right;
            case BiggerEqualToken:
                return left >= right;
            case SmallerEqualToken:
                return left <= right;
            default:
                throw runtime_error("Unexpected binary operator");
        }
    }

    ParenthesizedExpressionSyntax *parenthesizedExpression = dynamic_cast<ParenthesizedExpressionSyntax *>(node);
    if (parenthesizedExpression)
        return evaluateExpression(parenthesizedExpression->getExpression());

    throw runtime_error("Unexpected node");
}
