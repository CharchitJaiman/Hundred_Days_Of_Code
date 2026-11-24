/*
Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*


*/

#include <stdio.h>

int main(void) {
    for (int group = 0; group < 5; group++) {
        int level = group <= 2 ? group : 4 - group;
        for (int star = 0; star < 2 * level + 1; star++) {
            puts("*");
        }
        if (group < 4) {
            putchar('\n');
        }
    }
    return 0;
}
