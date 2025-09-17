#include "isogram.h"
#include <stddef.h>

bool is_isogram(const char phrase[])
{
    if (phrase == NULL) {
        return false;
    }

    bool letters[26] = { false };
    for (const char *p = phrase; *p != '\0'; p++) {
        char c = *p;
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A'; // Convert to lowercase
        }
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            if (letters[index]) {
                return false; // Duplicate letter found
            }
            letters[index] = true;
        }
    }
    return true;
}
