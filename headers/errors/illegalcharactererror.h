#pragma once

#include "error.h"

/**
 * @brief Represents a illigal character error.
 */
class IllegalCharacterError : public Error {
public:
    /**
     * @brief Constructs a illigal character error object with the given text span and message.
     * @param span The text span associated with the error.
     * @param text The error text.
     */
    IllegalCharacterError(string text);

    /**
     * @brief Gets the text span associated with the error.
     * @return The text span.
     */
    string getText();

    /**
     * @brief Gets the error message.
     * @return The error message.
     */
    string getMessage() override;

private:
    IllegalCharacterError() = default;

    string mText;
};
