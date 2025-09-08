#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    if (!lhs || !rhs) {
        return -1; // Handle NULL pointers
    }

    int len1 = 0, len2 = 0;
    while (lhs[len1] != '\0') len1++;
    while (rhs[len2] != '\0') len2++;

    if (len1 != len2) {
        return -1; // Strands must be of equal length
    }

    int distance = 0;
    for (int i = 0; i < len1; i++) {
        if (lhs[i] != rhs[i]) {
            distance++;
        }
    }

    return distance;
}
