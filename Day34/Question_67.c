/*
Insert an element in an array at a given position.
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
    int position, value;
    if (scanf("%d %d", &position, &value) != 2) {
        return 1;
    }
    if (position < 0 || position > n) {
        free(values);
        return 1;
    }
    for (int i = n; i > position; i--) {
        values[i] = values[i - 1];
    }
    values[position] = value;
    print_array(values, n + 1);
    free(values);
    return 0;
}
