#pragma once

/**
 * @brief Represents the different types of values in the XOR-Lang programming language.
 */
enum class ValueType {
    /**
     * @brief Represents a number value.
     */
    Number,

    /**
     * @brief Represents a string value.
     */
    String,

    /**
     * @brief Represents a boolean value.
     */
    Boolean,

    /**
     * @brief Represents a list value.
     */
    List,

    /**
     * @brief Represents a continue value.
     */
    ContinueType,

    /**
     * @brief Represents a break value.
     */
    BreakType,

    /**
     * @brief Represents a null value.
     */
    Null,
};
