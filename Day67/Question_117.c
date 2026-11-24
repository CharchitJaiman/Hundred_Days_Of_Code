/*
Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.
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
    int m;
    int *b = read_list(&m);
    if (!b) {
        free(a);
        return 1;
    }
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i || j) {
            putchar(' ');
        }
        int value;
        if (j == m || (i < n && a[i] <= b[j])) {
            value = a[i++];
        } else {
            value = b[j++];
        }
        printf("%d", value);
    }
    putchar('\n');
    free(b);
    free(a);
    return 0;
}
