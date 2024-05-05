#pragma once

#include <string>
#include "textspan.h"

using namespace std;

/**
 * @file error.h
 * @brief Contains the declaration of the Error class.
 */

 /**
  * @class Error
  * @brief Represents an error.
  *
  * The `Error` class represents an error that occurred during the parsing or execution of the XOR language.
  * It provides a method for getting the error message.
  */
class Error {
public:
    /**
     * @brief Gets the error message.
     * @return The error message.
     */
    string virtual getMessage() = 0;
};
