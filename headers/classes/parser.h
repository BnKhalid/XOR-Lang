#pragma once

#include "lexer.h"
#include "../utils/numberexpressionsyntax.h"
#include "../utils/binaryexpressionsyntax.h"
#include "../utils/syntaxtree.h"

/**
 * @class Parser
 * @brief Parses a string into an expression syntax tree.
 */
class Parser {
public:
    /**
     * @brief Constructs a Parser object with the given input line.
     * @param line The input line to be parsed.
     */
    Parser(string line);

    /**
     * @brief Parses the input line and returns the root expression syntax node.
     * @return The root expression syntax node.
     */
    ExpressionSyntax *parseExpression();

    SyntaxTree *parse();

    vector<string> getDiagnostics();

private:
    int mPosition = 0;
    vector<SyntaxToken> mTokens;
    vector<string> mDiagnostics;

    /**
     * @brief Peeks at the token at the specified offset from the current position.
     * @param offset The offset from the current position.
     * @return A pointer to the token at the specified offset, or nullptr if the offset is out of range.
     */
    SyntaxToken *peek(int offset);

    /**
     * @brief Gets the current token.
     * @return A pointer to the current token.
     */
    SyntaxToken *current();

    /**
     * @brief Advances to the next token and returns it.
     * @return A pointer to the next token.
     */
    SyntaxToken *nextToken();

    /**
     * @brief Matches the current token with the specified kind and advances to the next token.
     * @param kind The kind of token to match.
     * @return A pointer to the matched token, or nullptr if the current token does not match the specified kind.
     */
    SyntaxToken *match(SyntaxKind kind);

    /**
     * @brief Parses a primary expression.
     * @return A pointer to the parsed primary expression syntax node.
     */
    ExpressionSyntax *parsePrimaryExpression();
};
