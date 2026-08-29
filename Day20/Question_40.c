/*
Write a program to find the 1’s complement of a binary number and print it.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int digit;
    while ((digit = getchar()) != EOF && !isspace((unsigned char)digit)) {
        if (digit != '0' && digit != '1') {
            return 1;
        }
        putchar(digit == '0' ? '1' : '0');
    }
    putchar('\n');
    return 0;
}
