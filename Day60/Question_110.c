/*
Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.
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
    int *a = read_list(&n);
    if (!a) {
        return 1;
    }
    int k;
    if (!read_integer(&k)) {
        free(a);
        return 1;
    }
    if (k <= 0 || k > n) {
        free(a);
        return 1;
    }
    for (int start = 0; start <= n - k; start++) {
        int largest = a[start];
        for (int j = 1; j < k; j++) {
            if (a[start + j] > largest) {
                largest = a[start + j];
            }
        }
        printf("%s%d", start ? " " : "", largest);
    }
    putchar('\n');
    free(a);
    return 0;
}
