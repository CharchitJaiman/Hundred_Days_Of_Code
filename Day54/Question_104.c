/*
Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
*/

#include <ctype.h>
#include <stdio.h>

static int read_integer(int *value) {
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && !isdigit(ch) && ch != '-' && ch != '+');
    if (ch == EOF) {
        return 0;
    }
    ungetc(ch, stdin);
    return scanf("%d", value) == 1;
}

int main(void) {
    int n;
    if (!read_integer(&n) || n < 1) {
        return 1;
    }
    long long total = (long long)n * (n + 1LL) / 2;
    int left = 1, right = n, pivot = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;
        if (square == total) {
            pivot = mid;
            break;
        }
        if (square < total) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", pivot);
    return 0;
}
