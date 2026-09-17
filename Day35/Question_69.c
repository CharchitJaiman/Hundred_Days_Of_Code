/*
Find the second largest element in an array.
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
    long long largest = LLONG_MIN, second = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (values[i] > largest) {
            second = largest;
            largest = values[i];
        } else if (values[i] < largest && values[i] > second) {
            second = values[i];
        }
    }
    if (second == LLONG_MIN) {
        puts("No second largest");
    } else {
        printf("%lld\n", second);
    }
    free(values);
    return 0;
}
