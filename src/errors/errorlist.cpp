#include "../../headers/errors/errorlist.h"

ErrorList::ErrorList() {}

void ErrorList::throwError(Error *error) {
    mList.push_back(error);
}

int ErrorList::size() {
    return mList.size();
}

bool ErrorList::empty() {
    return mList.empty();
}

Error *ErrorList::operator[](int index) {
    return mList[index];
}

