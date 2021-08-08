#include "util.h"

#include <malloc.h>
#include <string.h>

char *my_strdup(char *s) {
    if (s) {
        size_t len = strlen(s);
        char *new_string = (char *) malloc(len + 1);
        if (new_string) {
            memcpy(new_string, s, len + 1);
        }
        return new_string;
    } else {
        return NULL;
    }
}
