/*
Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
*/

#include <stdio.h>
#include <string.h>

enum Operation { ADD, SUBTRACT, MULTIPLY };

int main(void) {
    char input[32];
    if (scanf("%31s", input) != 1) {
        return 1;
    }
    const char *names[] = {"ADD", "SUBTRACT", "MULTIPLY"};
    enum Operation choice;
    for (choice = ADD; choice <= MULTIPLY; choice++) {
        if (strcmp(input, names[choice]) == 0) {
            break;
        }
    }
    if (choice > MULTIPLY) {
        return 1;
    }
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }

    long long result;
    switch (choice) {
    case ADD:
        result = (long long)a + b;
        break;
    case SUBTRACT:
        result = (long long)a - b;
        break;
    case MULTIPLY:
        result = (long long)a * b;
        break;
    default:
        return 1;
    }
    printf("%lld\n", result);
    return 0;
}
