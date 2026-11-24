/*
Write a program to convert temperature from Celsius to Fahrenheit.
*/

#include <stdio.h>

int main(void) {
    double celsius;
    if (scanf("%lf", &celsius) != 1) {
        return 1;
    }
    printf("Fahrenheit=%g\n", 32 + celsius * 9 / 5);
    return 0;
}
