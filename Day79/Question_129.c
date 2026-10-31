/*
A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
*/

#include <stdio.h>

int main(void) {
    FILE *file = fopen("numbers.txt", "r");
    if (!file) {
        perror("numbers.txt");
        return 1;
    }
    int value, scanned;
    size_t count = 0;
    long long sum = 0;
    while ((scanned = fscanf(file, "%d", &value)) == 1) {
        sum += value;
        count++;
    }
    int failed = ferror(file) || scanned != EOF;
    fclose(file);
    if (failed) {
        return 1;
    }
    if (!count) {
        puts("Sum = 0\nAverage = undefined");
        return 0;
    }
    printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / count);
    return 0;
}
