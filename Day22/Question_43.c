/*
Write a program to check if a number is a strong number.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    int sum = 0, rest = number;
    if (number >= 0) {
        do {
            int digit = rest % 10, factorial = 1;
            for (int i = 2; i <= digit; i++) {
                factorial *= i;
            }
            sum += factorial;
            rest /= 10;
        } while (rest);
    }
    puts(sum == number ? "Strong number" : "Not strong number");
    return 0;
}
