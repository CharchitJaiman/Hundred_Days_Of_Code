/*
Write a program to check if a number is an Armstrong number.
*/

#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    int digits = 1;
    for (int rest = number; rest >= 10; rest /= 10) {
        digits++;
    }
    long long sum = 0;
    for (int rest = number; rest > 0; rest /= 10) {
        int digit = rest % 10;
        long long power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
    }
    puts(sum == number ? "Armstrong" : "Not Armstrong");
    return 0;
}
