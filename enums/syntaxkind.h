#pragma once

/**
 * @brief Represents the different kinds of syntax tokens in the XOR language.
 */
enum SyntaxKind {
    /**
     * @brief Represents a number token.
     */
    NumberToken,

    /**
     * @brief Represents a whitespace token.
     */
    WhiteSpaceToken,

    /**
     * @brief Represents a plus token.
     */
    PlusToken,

    /**
     * @brief Represents a minus token.
     */
    MinusToken,

    /**
     * @brief Represents a star token.
     */
    StarToken,

    /**
     * @brief Represents a slash token.
     */
    SlashToken,

    /**
     * @brief Represents an open parenthesis token.
     */
    OpenParenthesisToken,

    /**
     * @brief Represents a close parenthesis token.
     */
    CloseParenthesisToken,

    /**
     * @brief Represents an end of line token.
     */
    EndOfLineToken,

    EndOfFileToken,

    /**
     * @brief Represents a bad token.
     */
    BadToken,

    /**
     * @brief Represents a number expression token.
     */
    NumberExpressionToken,

    /**
     * @brief Represents a binary expression token.
     */
    BinaryExpressionToken,

    /**
     * @brief Represents an expression token.
     */
    ExpressionToken
};

