/*
Write a program to calculate the area and circumference of a circle given its radius.
*/

#include <stdio.h>

int main(void) {
    double radius;
    if (scanf("%lf", &radius) != 1) {
        return 1;
    }
    if (radius < 0) {
        return 1;
    }
    const double pi = 3.141592653589793;
    printf("Area=%.2f, Circumference=%.2f\n", pi * radius * radius, 2 * pi * radius);
    return 0;
}
