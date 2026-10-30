/*
Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("text.txt", "r");
    if (!file) {
        perror("text.txt");
        return 1;
    }
    size_t vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            if (strchr("aeiou", tolower(ch))) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    int failed = ferror(file);
    fclose(file);
    if (failed) {
        return 1;
    }
    printf("Vowels: %zu\nConsonants: %zu\n", vowels, consonants);
    return 0;
}
