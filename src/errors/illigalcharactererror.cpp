#include "../../headers/errors/illigalcharactererror.h"

IlligalCharacterError::IlligalCharacterError(string text)
    : mText(text) {}

string IlligalCharacterError::getText() {
    return mText;
}

string IlligalCharacterError::getMessage() {
    return "Illigal character error\nCharacter: " + mText + "\n";
}

