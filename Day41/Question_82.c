/*
Print each character of a string on a new line.
*/

#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        printf("%c\n", ch);
    }
    return 0;
}
