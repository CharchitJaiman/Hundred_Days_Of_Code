/*
Write a program to check if a number is a perfect number.
*/

#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    long long sum = number > 1 ? 1 : 0;
    for (int d = 2; d <= number / d; d++) {
        if (number % d == 0) {
            sum += d;
            if (d != number / d) {
                sum += number / d;
            }
        }
    }
    puts(number > 0 && sum == number ? "Perfect number" : "Not perfect number");
    return 0;
}
