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
     * @brief Represents a division by zero error.
     */
    DIVISION_BY_ZERO,
};