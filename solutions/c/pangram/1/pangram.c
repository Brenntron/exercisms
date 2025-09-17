#include "pangram.h"
#include <stddef.h>

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
        return false;

    bool letters[26] = { false };
    const char *ptr = sentence;

    while (*ptr) {
        char ch = *ptr;
        if (ch >= 'A' && ch <= 'Z') {
            letters[ch - 'A'] = true;
        } else if (ch >= 'a' && ch <= 'z') {
            letters[ch - 'a'] = true;
        }
        ptr++;
    }

    for (int i = 0; i < 26; i++) {
        if (!letters[i])
            return false;
    }

    return true;
}
