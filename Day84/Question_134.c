/*
Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
*/

#include <stdio.h>
#include <string.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main(void) {
    char input[32];
    if (scanf("%31s", input) != 1) {
        return 1;
    }
    const char *names[] = {"SUCCESS", "FAILURE", "TIMEOUT"};
    enum Status choice;
    for (choice = SUCCESS; choice <= TIMEOUT; choice++) {
        if (strcmp(input, names[choice]) == 0) {
            break;
        }
    }
    if (choice > TIMEOUT) {
        return 1;
    }

    const char *messages[] = {"Operation successful", "Operation failed",
                              "Operation timed out"};
    puts(messages[choice]);
    return 0;
}
