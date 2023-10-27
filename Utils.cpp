#include "Utils.h"

char* copyString(const char* str) {
    if (!str) {
        return nullptr;
    }
    char* newStr = new char[strlen(str) + 1];
    strcpy(newStr, str);
    return newStr;
}
