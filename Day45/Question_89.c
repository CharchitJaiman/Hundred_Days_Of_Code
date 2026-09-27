/*
Count frequency of a given character in a string.
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
    int target = getchar();
    if (target == EOF) {
        free(text);
        return 1;
    }
    size_t count = 0;
    for (size_t i = 0; text[i]; i++) {
        if ((unsigned char)text[i] == target) {
            count++;
        }
    }
    printf("%zu\n", count);
    free(text);
    return 0;
}
