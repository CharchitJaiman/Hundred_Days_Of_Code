/*
Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.

N.B:
- Print the output for each element in a comma separated fashion.
- Do not use Stack, use brute force approach (nested loop) to solve.
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
    for (int i = 0; i < n; i++) {
        int greater = -1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                greater = a[j];
                break;
            }
        }
        printf("%s%d", i ? ", " : "", greater);
    }
    putchar('\n');
    free(a);
    return 0;
}
