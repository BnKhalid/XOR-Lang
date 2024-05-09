#include "../../headers/errors/textspan.h"

TextSpan::TextSpan(int start, int length) {
    start = start;
    length = length;
}

int TextSpan::getStart() {
    return start;
}

int TextSpan::getLength() {
    return length;
}

int TextSpan::getEnd() {
    return start + length;
}
