/*
Write a program to calculate the factorial of a number.
*/

#include <limits.h>
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (n < 0) {
        return 1;
    }
    unsigned long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        if (factorial > ULLONG_MAX / (unsigned)i) {
            puts("Overflow");
            return 0;
        }
        factorial *= i;
    }
    printf("%llu\n", factorial);
    return 0;
}
