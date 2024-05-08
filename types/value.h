#pragma once

#include "../enums/valuetype.h"

using namespace std;


/**
 * @brief Represents a value in the XOR-Lang programming language.
 *
 * The `Value` struct is used to store a value of any type in XOR-Lang.
 * It consists of a void pointer `val` that can point to the actual value,
 * and a string `type` that specifies the type of the value.
 */
struct Value {
    /**
     * @brief Constructs a `Value` struct with a null value and type.
     */
    Value() : val(nullptr), type(ValueType::Null) {}

    /**
     * @brief Constructs a `Value` struct with the given value and type.
     * @param value The value to be stored.
     * @param type The type of the value.
     */
    Value(void *value, ValueType type) : val(value), type(type) {}

    /**
     * @brief The value of the `Value` struct.
     */
    void *val = nullptr;

    /**
     * @brief The type of the `Value` struct.
     */
    ValueType type = ValueType::Null;
};
