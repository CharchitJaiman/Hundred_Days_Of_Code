/*
Write a program to swap the first and last digit of a number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    long long magnitude = llabs((long long)number), place = 1;
    while (magnitude / place >= 10) {
        place *= 10;
    }
    if (place > 1) {
        long long first = magnitude / place, last = magnitude % 10;
        magnitude += (last - first) * (place - 1);
    }
    printf("%lld\n", number < 0 ? -magnitude : magnitude);
    return 0;
}
