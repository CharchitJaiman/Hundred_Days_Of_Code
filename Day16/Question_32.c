/*
Write a program to check if a number is a palindrome.
*/

#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }
    long long reversed = 0;
    for (int rest = number; rest > 0; rest /= 10) {
        reversed = reversed * 10 + rest % 10;
    }
    puts(number == reversed ? "Palindrome" : "Not palindrome");
    return 0;
}
