/*
Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
*/

#include <stdio.h>

int main(void) {
    FILE *file = fopen("data.txt", "ab+");
    if (!file) {
        perror("data.txt");
        return 1;
    }
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return 1;
    }
    long size = ftell(file);
    if (size < 0) {
        fclose(file);
        return 1;
    }
    if (size) {
        if (fseek(file, -1, SEEK_END) != 0) {
            fclose(file);
            return 1;
        }
        int last = fgetc(file);
        if (last == EOF || fseek(file, 0, SEEK_END) != 0) {
            fclose(file);
            return 1;
        }
        if (last != '\n') {
            fputc('\n', file);
        }
    }
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != '\r') {
            fputc(ch, file);
        }
    }
    fputc('\n', file);
    int failed = ferror(file);
    if (fclose(file) != 0 || failed) {
        return 1;
    }
    puts("File updated successfully with appended text.");
    return 0;
}
