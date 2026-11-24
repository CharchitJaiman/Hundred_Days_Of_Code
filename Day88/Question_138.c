/*
Print all enum names and integer values using a loop.
*/

#include <stdio.h>

enum Color { RED, YELLOW, GREEN };

int main(void) {
    const char *names[] = {"RED", "YELLOW", "GREEN"};
    for (enum Color color = RED; color <= GREEN; color++) {
        printf("%s=%d\n", names[color], color);
    }
    return 0;
}
