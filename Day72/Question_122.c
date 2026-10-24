/*
Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
*/

#include <stdio.h>

int main(void) {
    FILE *file = fopen("info.txt", "r");
    if (!file) {
        perror("info.txt");
        return 1;
    }
    char line[512];
    while (fgets(line, sizeof line, file)) {
        if (fputs(line, stdout) == EOF) {
            fclose(file);
            return 1;
        }
    }
    int failed = ferror(file);
    fclose(file);
    return failed ? 1 : 0;
    return 0;
}
