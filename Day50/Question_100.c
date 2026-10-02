/*
Print all sub-strings of a string.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static char *read_line(void) {
    size_t length = 0, capacity = 64;
    char *text = malloc(capacity);
    if (!text) {
        return NULL;
    }
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length == capacity - 1) {
            if (capacity > SIZE_MAX / 2) {
                free(text);
                return NULL;
            }
            capacity *= 2;
            char *larger = realloc(text, capacity);
            if (!larger) {
                free(text);
                return NULL;
            }
            text = larger;
        }
        text[length++] = (char)ch;
    }
    if (length && text[length - 1] == '\r') {
        length--;
    }
    text[length] = '\0';
    return text;
}

int main(void) {
    char *text = read_line();
    if (!text) {
        return 1;
    }
    for (size_t start = 0; text[start]; start++) {
        for (size_t end = start; text[end]; end++) {
            if (start || end) {
                putchar(',');
            }
            fwrite(text + start, 1, end - start + 1, stdout);
        }
    }
    putchar('\n');
    free(text);
    return 0;
}
