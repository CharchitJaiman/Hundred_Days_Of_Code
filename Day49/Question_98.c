/*
Print initials of a name with the surname displayed in full.
*/

#include <ctype.h>
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
    char *word = strtok(text, " \t");
    int initials = 0;
    while (word) {
        char *next = strtok(NULL, " \t");
        if (next) {
            printf("%c.", toupper((unsigned char)*word));
            initials = 1;
        } else {
            if (initials) {
                putchar(' ');
            }
            printf("%s", word);
        }
        word = next;
    }
    putchar('\n');
    free(text);
    return 0;
}
