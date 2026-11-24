/*
Search for an element in an array using linear search.
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
    int target;
    if (scanf("%d", &target) != 1) {
        return 1;
    }
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (values[i] == target) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        puts("-1");
    } else {
        printf("Found at index %d\n", index);
    }
    free(values);
    return 0;
}
