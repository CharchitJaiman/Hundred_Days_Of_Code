/*
Remove all vowels from a string.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if (!strchr("aeiou", tolower(ch))) {
            putchar(ch);
        }
    }
    putchar('\n');
    return 0;
}
