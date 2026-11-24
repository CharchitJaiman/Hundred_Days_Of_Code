/*
Merge two arrays.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int *read_array(int *length) {
    if (scanf("%d", length) != 1 || *length < 0) {
        return NULL;
    }
    /* The extra slot also allows insertion and represents an empty array. */
    if ((size_t)*length >= SIZE_MAX / sizeof(int)) {
        return NULL;
    }
    int *values = malloc(((size_t)*length + 1) * sizeof *values);
    if (!values) {
        return NULL;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            return NULL;
        }
    }
    return values;
}

int main(void) {
    int n;
    int *values = read_array(&n);
    if (!values) {
        return 1;
    }
    int m;
    int *second = read_array(&m);
    if (!second) {
        free(values);
        return 1;
    }
    size_t length = (size_t)n + (size_t)m;
    if (length > SIZE_MAX / sizeof(int)) {
        free(second);
        free(values);
        return 1;
    }
    int *merged = malloc((length ? length : 1) * sizeof *merged);
    if (!merged) {
        free(second);
        free(values);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        merged[i] = values[i];
    }
    for (int j = 0; j < m; j++) {
        merged[(size_t)n + j] = second[j];
    }
    for (size_t i = 0; i < length; i++) {
        printf("%s%d", i ? " " : "", merged[i]);
    }
    putchar('\n');
    free(merged);
    free(second);
    free(values);
    return 0;
}
