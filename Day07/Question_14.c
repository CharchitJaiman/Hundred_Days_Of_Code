/*
Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char letter;
    if (scanf(" %c", &letter) != 1) {
        return 1;
    }
    int lower = tolower((unsigned char)letter);
    if (!isalpha(lower)) {
        puts("Not a letter");
    } else if (strchr("aeiou", lower)) {
        puts("Vowel");
    } else {
        puts("Consonant");
    }
    return 0;
}
