/*
Count positive, negative, and zero elements in an array.
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
    int positive = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        if (values[i] > 0) {
            positive++;
        } else if (values[i] < 0) {
            negative++;
        }
    }
    printf("Positive=%d, Negative=%d, Zero=%d\n", positive, negative, n - positive - negative);
    free(values);
    return 0;
}
