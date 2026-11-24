/*
Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *file = fopen("sample.txt", "r");
    if (!file) {
        perror("sample.txt");
        return 1;
    }
    size_t characters = 0, words = 0, lines = 0;
    int ch, last = '\n', in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
        last = ch;
    }
    if (last != '\n') {
        lines++;
    }
    int failed = ferror(file);
    fclose(file);
    if (failed) {
        return 1;
    }
    printf("Characters: %zu\nWords: %zu\nLines: %zu\n", characters, words, lines);
    return 0;
}
