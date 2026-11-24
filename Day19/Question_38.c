/*
Write a program to find the sum of digits of a number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    int sum = 0;
    for (long long rest = llabs((long long)number); rest; rest /= 10) {
        sum += (int)(rest % 10);
    }
    printf("%d\n", sum);
    return 0;
}
