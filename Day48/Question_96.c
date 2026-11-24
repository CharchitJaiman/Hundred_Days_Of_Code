/*
Reverse each word in a sentence without changing the word order.
*/

#include <ctype.h>
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
    size_t i = 0;
    while (text[i]) {
        if (isspace((unsigned char)text[i])) {
            putchar((unsigned char)text[i++]);
            continue;
        }
        size_t begin = i;
        while (text[i] && !isspace((unsigned char)text[i])) {
            i++;
        }
        for (size_t j = i; j > begin; j--) {
            putchar((unsigned char)text[j - 1]);
        }
    }
    putchar('\n');
    free(text);
    return 0;
}
