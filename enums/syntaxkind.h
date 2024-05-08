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
     * @brief Represents a string token.
     */
    StringToken,

    /**
     * @brief Represents a true keyword token.
     */
    TrueToken,

    /**
     * @brief Represents a false keyword token.
     */
    FalseToken,

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
     * @brief Represents an open square bracket token.
     */
    OpenSquareBracketToken,

    /**
     * @brief Represents a close square bracket token.
     */
    CloseSquareBracketToken,

    /**
     * @brief Represents an equal token.
     */
    EqualToken,

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
     * @brief Represents an ampersand ampersand token.
     */
    AmpersandAmpersandToken,

    /**
     * @brief Represents a pipe pipe token.
     */
    PipePipeToken,

    /**
     * @brief Represents a equal equal token.
     */
    EqualEqualToken,

    /**
     * @brief Represents a bang equal token.
     */
    BangEqualToken,

    /**
     * @brief Represents a bigger token.
     */
    BiggerToken,

    /**
     * @brief Represents a smaller token.
     */
    SmallerToken,

    /**
     * @brief Represents a bigger equal token.
     */
    BiggerEqualToken,

    /**
     * @brief Represents a smaller equal token.
     */
    SmallerEqualToken,

    /**
     * @brief Represents a bang token.
     */
    BangToken,

    /**
     * @brief Represents a comma token.
     */
    CommaToken,


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
    Expression,

    /**
     * @brief Represents a name expression token.
     */
    NameExpression,

    /**
     * @brief Represents a string expression token.
     */
    StringExpression,

    /**
     * @brief Represents an assignment expression token.
     */
    AssignmentExpression,

    /**
     * @brief Represents a number expression token.
     */
    LiteralExpression,

    /**
     * @brief Represents a unary expression token.
     */
    UnaryExpression,

    /**
     * @brief Represents a binary expression token.
     */
    BinaryExpression,

    /**
     * @brief Represents a parenthesized expression token.
     */
    ParenthesizedExpression,

    /**
     * @brief Represents a list expression token.
     */
    ListExpression,

    /**
     * @brief Represents a loop expression token.
     */
    LoopExpression,

    /**
     * @brief Represents an if expression token.
     */
    IfExpression,


    /**
     * @brief Represents a statement token.
     */
    Statement,

    /**
     * @brief Represents a while token.
     */
    WhileToken,

    /**
     * @brief Represents a for token.
     */
    ForToken,

    /**
     * @brief Represents a do token.
     */
    DoToken,

    /**
     * @brief Represents a colon token.
     */
    ColonToken,

    /**
     * @brief Represents a if token.
     */
    IfToken,

    /**
     * @brief Represents a then token.
     */
    ThenToken,
};

