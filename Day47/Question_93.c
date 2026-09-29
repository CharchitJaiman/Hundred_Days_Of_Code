/*
Check if two strings are anagrams of each other.
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *other = read_line();
    if (!other) {
        free(text);
        return 1;
    }
    size_t first[UCHAR_MAX + 1] = {0}, second[UCHAR_MAX + 1] = {0};
    for (size_t i = 0; text[i]; i++) {
        first[(unsigned char)text[i]]++;
    }
    for (size_t i = 0; other[i]; i++) {
        second[(unsigned char)other[i]]++;
    }
    puts(memcmp(first, second, sizeof first) == 0 ? "Anagrams" : "Not anagrams");
    free(other);
    free(text);
    return 0;
}
