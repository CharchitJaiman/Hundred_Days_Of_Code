/*
Write a program to input two numbers and display their sum, difference, product, and quotient.
*/

#include <stdio.h>

int main(void) {
    int first, second;
    if (scanf("%d %d", &first, &second) != 2) {
        return 1;
    }
    printf("Sum=%lld, Diff=%lld, Product=%lld, Quotient=", (long long)first + second,
           (long long)first - second, (long long)first * second);
    if (second == 0) {
        puts("undefined");
    } else {
        printf("%lld\n", (long long)first / second);
    }
    return 0;
}
