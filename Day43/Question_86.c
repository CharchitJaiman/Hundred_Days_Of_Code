/*
Check if a string is a palindrome.
*/

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
    size_t length = strlen(text);
    int palindrome = 1;
    for (size_t i = 0; i < length / 2; i++) {
        if (text[i] != text[length - 1 - i]) {
            palindrome = 0;
            break;
        }
    }
    puts(palindrome ? "Palindrome" : "Not palindrome");
    free(text);
    return 0;
}
