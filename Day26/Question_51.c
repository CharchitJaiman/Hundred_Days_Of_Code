/*
Write a program to print the following pattern:
    5
   45
  345
 2345
12345
*/

#include <stdio.h>

int main(void) {
    for (int row = 1; row <= 5; row++) {
        for (int space = row; space < 5; space++) {
            putchar(' ');
        }
        for (int col = 1; col <= row; col++) {
            putchar('0' + 5 - row + col);
        }
        putchar('\n');
    }
    return 0;
}
