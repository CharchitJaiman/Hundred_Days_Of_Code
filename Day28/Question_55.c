/*
Write a program to print all the prime numbers from 1 to n.
*/

#include <stdio.h>

static int is_prime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= number / divisor; divisor++) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (long long number = 2; number <= n; number++) {
        if (is_prime((int)number)) {
            printf("%s%lld", number == 2 ? "" : " ", number);
        }
    }
    putchar('\n');
    return 0;
}
