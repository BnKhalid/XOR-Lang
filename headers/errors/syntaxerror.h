#pragma once

#include "error.h"
#include "../utils/utilities.h"
#include "../../enums/syntaxkind.h"

/**
 * @brief Represents a syntax error.
 */
class SyntaxError : public Error {
public:
    /**
     * @brief Constructs a syntax error object with the given text span and message.
     * @param span The text span associated with the error.
     * @param text The error text.
     */
    SyntaxError(SyntaxKind expected, SyntaxKind found);


    /**
     * @brief Gets the expected token.
     * @return The expected token.
     */
    SyntaxKind getExpected();

    /**
     * @brief Gets the error message.
     * @return The error message.
     */
    string getMessage() override;

private:
    SyntaxError() = default;

    SyntaxKind mExpected;
    SyntaxKind mFound;
};
