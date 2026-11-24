/*
Write a program to find the product of odd digits of a number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    long long magnitude = llabs((long long)number), product = 1, divisor = 1;
    int found = 0;
    for (long long rest = magnitude; rest; rest /= 10) {
        int digit = (int)(rest % 10);
        if (digit % 2) {
            product *= digit;
            found = 1;
        }
        if (rest >= 10) {
            divisor *= 10;
        }
    }
    printf("%lld (", product);
    if (!found) {
        printf("no odd digits, assume 1");
    } else {
        int first = 1;
        for (; divisor; divisor /= 10) {
            int digit = (int)(magnitude / divisor % 10);
            if (digit % 2) {
                printf("%s%d", first ? "" : "*", digit);
                first = 0;
            }
        }
    }
    puts(")");
    return 0;
}
