#include "../../headers/errors/illegalcharactererror.h"

IllegalCharacterError::IllegalCharacterError(string text)
    : mText(text) {}

string IllegalCharacterError::getText() {
    return mText;
}

string IllegalCharacterError::getMessage() {
    return "Illegal character error\nCharacter: " + mText + "\n";
}

