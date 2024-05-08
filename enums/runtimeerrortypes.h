#pragma once

/**
 * @brief Represents the different types of runtime errors.
 */
enum class RuntimeErrorType {
    /**
     * @brief Represents an overflow error.
     */
    OVERFLOW,

    /**
     * @brief Represents an undefined variable error.
     */
    UNDEFINED_VARIABLE,

    /**
     * @brief Represents a division by zero error.
     */
    DIVISION_BY_ZERO,

    /**
     * @brief Represents an invalid operation error.
     */
    INVALID_OPERATOR
};