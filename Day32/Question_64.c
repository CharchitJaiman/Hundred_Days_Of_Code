/*
Find the digit that occurs the most times in an integer number.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    size_t frequency[10] = {0};
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isdigit((unsigned char)ch)) {
            frequency[ch - '0']++;
        }
    }
    int most = 0;
    for (int i = 1; i < 10; i++) {
        if (frequency[i] > frequency[most]) {
            most = i;
        }
    }
    if (!frequency[most]) {
        return 1;
    }
    printf("%d\n", most);
    return 0;
}
