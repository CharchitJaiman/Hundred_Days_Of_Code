/*
Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*
*/

#include <stdio.h>

int main(void) {
    for (int row = 0; row < 9; row++) {
        int level = row <= 4 ? row : 8 - row;
        for (int star = 0; star < 2 * level + 1; star++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
