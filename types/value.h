#pragma once
#include <string>

/**
 * @brief Represents a value that can hold different types of data.
 *
 * The Value struct is used to store values of different types, including integers,
 * doubles, characters, and strings. Each value is stored as a pointer to the
 * corresponding type. If a value is not set, the pointer will be nullptr.
 */
struct Value {
    /**
     * @brief Pointer to an integer value.
     */
    int *pInt = nullptr;

    /**
     * @brief Pointer to a double value.
     */
    double *pDouble = nullptr;

    /**
     * @brief Pointer to a character value.
     */
    char *pChar = nullptr;

    /**
     * @brief Pointer to a string value.
     */
    std::string *pString = nullptr;
};

