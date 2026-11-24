/*
Write a program to swap two numbers using a third variable.
*/

#include <stdio.h>

int main(void) {
    int first, second;
    if (scanf("%d %d", &first, &second) != 2) {
        return 1;
    }
    int temporary = first;
    first = second;
    second = temporary;
    printf("After swap: %d %d\n", first, second);
    return 0;
}
