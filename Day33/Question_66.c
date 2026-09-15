/*
Insert an element in a sorted array at the appropriate position.
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
    int value;
    if (scanf("%d", &value) != 1) {
        return 1;
    }
    int position = n;
    while (position > 0 && values[position - 1] > value) {
        values[position] = values[position - 1];
        position--;
    }
    values[position] = value;
    print_array(values, n + 1);
    free(values);
    return 0;
}
