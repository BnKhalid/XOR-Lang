#include "../../headers/errors/runtimeerror.h"

RuntimeError::RuntimeError(string text, RuntimeErrorType type)
    : mText(text)
    , mType(type) {}

string RuntimeError::getText() {
    return mText;
}

string RuntimeError::getMessage() {
    string message = "Runtime error, ";
    switch (mType) {
        case RuntimeErrorType::OVERFLOW:
            message += "Overflow\nNumber " + mText + " is too large to be stored in INT32 variable type.\n";
            break;
        case RuntimeErrorType::DIVISION_BY_ZERO:
            message += "Division by zeron\n";
            break;
    }
    return message;
}
