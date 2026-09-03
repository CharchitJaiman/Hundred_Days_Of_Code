/*
Write a program to print the following pattern:
*****
 ****
  ***
   **
    *
*/

#include <stdio.h>

int main(void) {
    for (int row = 1; row <= 5; row++) {
        for (int space = 1; space < row; space++) {
            putchar(' ');
        }
        for (int col = 1; col <= 6 - row; col++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
