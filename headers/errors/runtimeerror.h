#pragma once

#include "../../enums/runtimeerrortypes.h"
#include "error.h"

/**
 * @brief Represents a runtime error.
 */
class RuntimeError : public Error {
public:
    /**
     * @brief Constructs a runtime error object with the given text span and message.
     * @param span The text span associated with the error.
     * @param text The error text.
     * @param type The runtime error type.
     */
    RuntimeError(string text, RuntimeErrorType type);

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
    string mText;               // The text span associated with the error.
    RuntimeErrorType mType;     // The runtime error type.

    /**
     * @brief Default constructor.
     */
    RuntimeError() = default;
};
