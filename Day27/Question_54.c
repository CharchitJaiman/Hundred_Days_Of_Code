/*
Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *

*/

#include <stdio.h>

int main(void) {
    for (int row = 0; row < 7; row++) {
        int level = row <= 3 ? row : 6 - row;
        for (int space = level; space < 3; space++) {
            putchar(' ');
        }
        for (int star = 0; star < 2 * level + 1; star++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
