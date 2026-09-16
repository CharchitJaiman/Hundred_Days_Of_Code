/*
Delete an element from an array.
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
static void print_array(const int *values, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s%d", i ? " " : "", values[i]);
    }
    putchar('\n');
}

int main(void) {
    int n;
    int *values = read_array(&n);
    if (!values) {
        return 1;
    }
    int position;
    if (scanf("%d", &position) != 1) {
        return 1;
    }
    if (position < 0 || position >= n) {
        free(values);
        return 1;
    }
    for (int i = position; i < n - 1; i++) {
        values[i] = values[i + 1];
    }
    print_array(values, n - 1);
    free(values);
    return 0;
}
