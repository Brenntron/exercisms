#include "binary.h"

int convert(const char *binary)
{
    int result = 0;
    if (*binary == '\0') {
        return INVALID;
    }
    while (*binary) {
        if (*binary != '0' && *binary != '1') {
            return INVALID;
        }
        result = (result << 1) | (*binary - '0');
        binary++;
    }
    return result;
}
