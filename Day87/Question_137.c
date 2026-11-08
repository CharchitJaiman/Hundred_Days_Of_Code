/*
Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
*/

#include <stdio.h>
#include <string.h>

enum Role { ADMIN, USER, GUEST };

int main(void) {
    char input[32];
    if (scanf("%31s", input) != 1) {
        return 1;
    }
    const char *names[] = {"ADMIN", "USER", "GUEST"};
    enum Role choice;
    for (choice = ADMIN; choice <= GUEST; choice++) {
        if (strcmp(input, names[choice]) == 0) {
            break;
        }
    }
    if (choice > GUEST) {
        return 1;
    }

    const char *messages[] = {"Welcome Admin!", "Welcome User!", "Welcome Guest!"};
    puts(messages[choice]);
    return 0;
}
