/*
Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (!input) {
        perror("input.txt");
        return 1;
    }
    FILE *output = fopen("output.txt", "w");
    if (!output) {
        perror("output.txt");
        fclose(input);
        return 1;
    }
    int ch, failed = 0;
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper(ch), output) == EOF) {
            failed = 1;
            break;
        }
    }
    if (ferror(input)) {
        failed = 1;
    }
    fclose(input);
    if (fclose(output) != 0 || failed) {
        return 1;
    }
    return 0;
}
