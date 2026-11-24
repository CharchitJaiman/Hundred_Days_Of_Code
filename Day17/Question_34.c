/*
Write a program to check if a number is prime.
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
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    puts(is_prime(number) ? "Prime" : "Not prime");
    return 0;
}
