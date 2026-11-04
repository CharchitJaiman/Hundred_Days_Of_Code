/*
Create an enum for months and print how many days each month has.
*/

#include <stdio.h>
#include <string.h>

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main(void) {
    char input[32];
    if (scanf("%31s", input) != 1) {
        return 1;
    }
    const char *names[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                           "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    enum Month choice;
    for (choice = JAN; choice <= DEC; choice++) {
        if (strcmp(input, names[choice]) == 0) {
            break;
        }
    }
    if (choice > DEC) {
        return 1;
    }

    if (choice == FEB) {
        puts("28 or 29 days");
    } else if (choice == APR || choice == JUN || choice == SEP || choice == NOV) {
        puts("30 days");
    } else {
        puts("31 days");
    }
    return 0;
}
