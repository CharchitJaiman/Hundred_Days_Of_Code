/*
Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
*/

#include <limits.h>
#include <stdio.h>

static int start_string(void) {
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && ch != '"');
    return ch != EOF;
}

int main(void) {
    if (!start_string()) {
        return 1;
    }
    size_t past[UCHAR_MAX + 1] = {0}, start = 0, best = 0, position = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '"') {
        if (past[ch] > start) {
            start = past[ch];
        }
        past[ch] = ++position;
        if (position - start > best) {
            best = position - start;
        }
    }
    if (ch == EOF) {
        return 1;
    }
    printf("%zu\n", best);
    return 0;
}
