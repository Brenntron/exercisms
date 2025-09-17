#include "two_fer.h"
#include <stddef.h>
#include <stdio.h>

void two_fer(char *buffer, const char *name) {
    if (name == NULL || name[0] == '\0') {
        snprintf(buffer, 100, "One for you, one for me.");
    } else {
        snprintf(buffer, 100, "One for %s, one for me.", name);
    }
}
