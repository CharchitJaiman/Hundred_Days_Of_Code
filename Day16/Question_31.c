/*
Write a program to take a number as input and print its equivalent binary representation.
*/

#include <stdio.h>

static void print_binary(long long number) {
    if (number >= 2) {
        print_binary(number / 2);
    }
    putchar('0' + (int)(number % 2));
}

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    long long magnitude = number;
    if (magnitude < 0) {
        putchar('-');
        magnitude = -magnitude;
    }
    print_binary(magnitude);
    putchar('\n');
    return 0;
}
