/*
Write a program to input two numbers and display their sum.
*/

#include <stdio.h>

int main(void) {
    int first, second;
    if (scanf("%d %d", &first, &second) != 2) {
        return 1;
    }
    printf("Sum = %lld\n", (long long)first + second);
    return 0;
}
