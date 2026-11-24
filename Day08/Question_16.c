/*
Write a program to input three numbers and find the largest among them using if–else.
*/

#include <stdio.h>

int main(void) {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        return 1;
    }
    double largest = a;
    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }
    printf("Largest is %g\n", largest);
    return 0;
}
