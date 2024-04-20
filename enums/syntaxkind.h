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
     * @brief Represents a false keyword token.
     */
    FalseKeywordToken,

    /**
     * @brief Represents a true keyword token.
     */
    TrueKeywordToken,

    /**
     * @brief Represents a bang token.
     */
    BangToken,

    /**
     * @brief Represents an ampersand ampersand token.
     */
    AmpersandAmpersandToken,

    /**
     * @brief Represents a pipe pipe token.
     */
    PipePipeToken,

    /**
     * @brief Represents an identifier token.
     */
    IdentifierToken,

    /**
     * @brief Represents an open parenthesis token.
     */
    OpenParenthesisToken,

    /**
     * @brief Represents a close parenthesis token.
     */
    CloseParenthesisToken,

    /**
     * @brief Represents a whitespace token.
     */
    WhiteSpaceToken,

    /**
     * @brief Represents an end of line token.
     */
    EndOfLineToken,

    /**
     * @brief Represents an end of file token.
     */
    EndOfFileToken,

    /**
     * @brief Represents a bad token.
     */
    BadToken,

    /**
     * @brief Represents an expression token.
     */
    ExpressionToken,

    /**
     * @brief Represents a number expression token.
     */
    LiteralExpressionToken,

    /**
     * @brief Represents a unary expression token.
     */
    UnaryExpressionToken,

    /**
     * @brief Represents a binary expression token.
     */
    BinaryExpressionToken,

    /**
     * @brief Represents a parenthesized expression token.
     */
    ParenthesizedExpressionToken
};

