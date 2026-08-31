/*
Write a program to find the sum of the series: 1 + 3/4 + 5/6 + 7/8 + … up to n terms.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (n < 1) {
        return 1;
    }
    double sum = 1;
    for (int term = 1; term < n; term++) {
        sum += (2.0 * term + 1) / (2.0 * term + 2);
    }
    printf("Approximate sum: %.1f\n", sum);
    return 0;
}
