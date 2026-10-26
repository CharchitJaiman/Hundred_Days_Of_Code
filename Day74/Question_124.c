/*
Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char source[512], destination[512];
    if (scanf("%511s %511s", source, destination) != 2 || strcmp(source, destination) == 0) {
        return 1;
    }
    FILE *input = fopen(source, "rb");
    if (!input) {
        perror(source);
        return 1;
    }
    FILE *output = fopen(destination, "wb");
    if (!output) {
        perror(destination);
        fclose(input);
        return 1;
    }
    int ch, failed = 0;
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(ch, output) == EOF) {
            failed = 1;
            break;
        }
    }
    if (ferror(input)) {
        failed = 1;
    }
    if (fclose(output) != 0) {
        failed = 1;
    }
    fclose(input);
    if (failed) {
        return 1;
    }
    printf("File copied successfully to %s\n", destination);
    return 0;
}
