/*
Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    char character;
    if (scanf(" %c", &character) != 1) {
        return 1;
    }
    unsigned char byte = (unsigned char)character;
    if (isupper(byte)) {
        puts("Uppercase alphabet");
    } else if (islower(byte)) {
        puts("Lowercase alphabet");
    } else if (isdigit(byte)) {
        puts("Digit");
    } else {
        puts("Special character");
    }
    return 0;
}
