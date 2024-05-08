#pragma once

#include <vector>
#include "../errors/error.h"
#include "../errors/illegalcharactererror.h"
#include "../errors/runtimeerror.h"
#include "../errors/syntaxerror.h"

using namespace std;

/**
 * @file errorlist.h
 * @brief Contains the declaration of the ErrorList class.
 */

 /**
 * @class ErrorList
 * @brief Represents a List of error messages.
 *
 * The ErrorList class is responsible for storing and managing a List of error messages.
 * It provides methods for pushing messages from the List.
 */
class ErrorList {
public:
    /**
     * @brief Constructs an ErrorList object.
     */
    ErrorList();

    /**
     * @brief Pushes an error onto the list.
     * @param error The error to push.
     */
    void throwError(Error *error);

    /**
     * @brief Gets the number of error messages on the list.
     * @return The number of error messages.
     */
    int size();

    /**
     * @brief Checks if the list is empty.
     * @return True if the list is empty, false otherwise.
     */
    bool empty();

    /**
     * @brief Gets the error message at the top of the list.
     * @return The error message at the top of the list.
     */
    Error *operator[](int index);

private:
    vector<Error *> mList; // The list of errors.
};
