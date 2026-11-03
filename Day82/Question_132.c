/*
Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
*/

#include <stdio.h>
#include <string.h>

enum Light { RED, YELLOW, GREEN };

int main(void) {
    char input[32];
    if (scanf("%31s", input) != 1) {
        return 1;
    }
    const char *names[] = {"RED", "YELLOW", "GREEN"};
    enum Light choice;
    for (choice = RED; choice <= GREEN; choice++) {
        if (strcmp(input, names[choice]) == 0) {
            break;
        }
    }
    if (choice > GREEN) {
        return 1;
    }

    const char *actions[] = {"Stop", "Wait", "Go"};
    puts(actions[choice]);
    return 0;
}
