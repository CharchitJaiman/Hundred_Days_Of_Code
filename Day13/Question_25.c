/*
Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
*/

#include <stdio.h>

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }
    char operation;
    if (scanf(" %c", &operation) != 1) {
        return 1;
    }
    switch (operation) {
    case '+':
        printf("%lld\n", (long long)a + b);
        break;
    case '-':
        printf("%lld\n", (long long)a - b);
        break;
    case '*':
        printf("%lld\n", (long long)a * b);
        break;
    case '/':
        if (!b) {
            puts("Division by zero");
        } else {
            printf("%g\n", (double)a / b);
        }
        break;
    case '%':
        if (!b) {
            puts("Division by zero");
        } else {
            printf("%lld\n", (long long)a % b);
        }
        break;
    default:
        puts("Invalid operator");
    }
    return 0;
}
