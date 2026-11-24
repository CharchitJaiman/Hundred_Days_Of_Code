/*
Print the initials of a name.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int beginning = 1, ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isspace(ch)) {
            beginning = 1;
        } else if (beginning) {
            printf("%c.", toupper(ch));
            beginning = 0;
        }
    }
    putchar('\n');
    return 0;
}
