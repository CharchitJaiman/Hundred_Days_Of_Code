/*
Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
*/

#include <stdio.h>

int main(void) {
    char name[512];
    if (scanf("%511s", name) != 1) {
        return 1;
    }
    FILE *file = fopen(name, "r");
    if (!file) {
        puts("Error: File does not exist!");
        return 0;
    }
    puts("File opened successfully.");
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    int failed = ferror(file);
    fclose(file);
    return failed ? 1 : 0;
    return 0;
}
