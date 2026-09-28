/*
Find the first repeating lowercase alphabet in a string.
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
    size_t counts[26] = {0};
    for (size_t i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            counts[text[i] - 'a']++;
        }
    }
    int found = 0;
    for (size_t i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z' && counts[text[i] - 'a'] > 1) {
            printf("%c\n", text[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        puts("-1");
    }
    free(text);
    return 0;
}
