/*
Write a program to print all factors of a given number.
*/

#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    if (number < 1) {
        return 1;
    }
    for (long long divisor = 1; divisor <= number; divisor++) {
        if (number % divisor == 0) {
            printf("%s%lld", divisor == 1 ? "" : " ", divisor);
        }
    }
    putchar('\n');
    return 0;
}
