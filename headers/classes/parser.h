#pragma once

#include "lexer.h"
#include "../utils/numberexpressionsyntax.h"
#include "../utils/binaryexpressionsyntax.h"
#include "../utils/parenthesizedexpressionsyntax.h"
#include "../utils/syntaxtree.h"

/**
 * @file parser.h
 * @brief Contains the declaration of the Parser class.
 */

 /**
  * @class Parser
  * @brief Represents a parser for the XOR language.
  *
  * The Parser class is responsible for parsing input lines and generating a syntax tree.
  * It provides methods for parsing expressions, matching tokens, and retrieving diagnostics.
  */
class Parser {
public:
    /**
     * @brief Constructs a Parser object with the given input line.
     * @param line The input line to be parsed.
     */
    Parser(string line);

    /**
     * @brief Parses a primary expression.
     * @return A pointer to the parsed primary expression syntax node.
     */
    ExpressionSyntax *parseTerm();

    /**
     * @brief Parses a factor expression.
     * @return A pointer to the parsed factor expression syntax node.
     */
    ExpressionSyntax *parseFactor();

    /**
     * @brief Parses the input line and generates a syntax tree.
     * @return A pointer to the generated syntax tree.
     */
    SyntaxTree *parse();

    /**
     * @brief Gets the diagnostics generated during parsing.
     * @return A vector of diagnostic messages.
     */
    vector<string> getDiagnostics();

private:
    int mPosition = 0; // The current position in the token list.
    vector<SyntaxToken> mTokens; // The list of tokens generated by the lexer.
    vector<string> mDiagnostics; // The list of diagnostic messages generated during parsing.

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
