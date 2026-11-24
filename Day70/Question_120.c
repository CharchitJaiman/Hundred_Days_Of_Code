/*
Write a program to take a string input. Change it to sentence case.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void emit(int ch, int *beginning) {
    if (isspace(ch)) {
        *beginning = 1;
        putchar(ch);
    } else if (isalpha(ch) || isdigit(ch)) {
        putchar(*beginning ? toupper(ch) : tolower(ch));
        *beginning = 0;
    } else {
        putchar(ch);
    }
}

int main(void) {
    char prefix[7] = {0};
    if (!fgets(prefix, sizeof prefix, stdin)) {
        return 1;
    }
    int beginning = 1;
    if (strcmp(prefix, "str = ") != 0) {
        for (size_t i = 0; prefix[i] && prefix[i] != '\n'; i++) {
            emit((unsigned char)prefix[i], &beginning);
        }
    }
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        emit(ch, &beginning);
    }
    putchar('\n');
    return 0;
}
