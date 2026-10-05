/*
Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.
*/

#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Read the bracketed list in the published input, including the "arr[] =" spelling. */
static int *read_list(int *length) {
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && ch != '[');
    if (ch == EOF) {
        return NULL;
    }
    do {
        ch = getchar();
    } while (ch != EOF && isspace(ch));
    if (ch == ']') {
        do {
            ch = getchar();
        } while (ch != EOF && isspace(ch));
        if (ch == '=') {
            return read_list(length);
        }
        if (ch != EOF) {
            ungetc(ch, stdin);
        }
        *length = 0;
        return calloc(1, sizeof(int));
    }
    if (ch == EOF) {
        return NULL;
    }
    ungetc(ch, stdin);
    int capacity = 8;
    *length = 0;
    int *values = malloc((size_t)capacity * sizeof *values);
    if (!values) {
        return NULL;
    }
    for (;;) {
        int value;
        if (scanf("%d", &value) != 1) {
            free(values);
            return NULL;
        }
        if (*length == capacity) {
            if (capacity > INT_MAX / 2 || (size_t)capacity > SIZE_MAX / sizeof(int) / 2) {
                free(values);
                return NULL;
            }
            capacity *= 2;
            int *larger = realloc(values, (size_t)capacity * sizeof *values);
            if (!larger) {
                free(values);
                return NULL;
            }
            values = larger;
        }
        values[(*length)++] = value;
        do {
            ch = getchar();
        } while (ch != EOF && isspace(ch));
        if (ch == ']') {
            return values;
        }
        if (ch != ',') {
            free(values);
            return NULL;
        }
    }
}

int main(void) {
    int n;
    int *a = read_list(&n);
    if (!a) {
        return 1;
    }
    long long right = 0, left = 0;
    for (int i = 0; i < n; i++) {
        right += a[i];
    }
    int pivot = -1;
    for (int i = 0; i < n; i++) {
        right -= a[i];
        if (left == right) {
            pivot = i;
            break;
        }
        left += a[i];
    }
    printf("%d\n", pivot);
    free(a);
    return 0;
}
