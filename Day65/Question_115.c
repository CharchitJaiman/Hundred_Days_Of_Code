/*
Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
*/

#include <stdio.h>

static int start_string(void) {
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && ch != '"');
    return ch != EOF;
}

int main(void) {
    int counts[26] = {0};
    for (int word = 0; word < 2; word++) {
        if (!start_string()) {
            return 1;
        }
        int ch;
        while ((ch = getchar()) != EOF && ch != '"') {
            if (ch < 'a' || ch > 'z') {
                return 1;
            }
            counts[ch - 'a'] += word ? -1 : 1;
        }
        if (ch == EOF) {
            return 1;
        }
    }
    int equal = 1;
    for (int i = 0; i < 26; i++) {
        if (counts[i]) {
            equal = 0;
        }
    }
    puts(equal ? "Anagram" : "Not Anagram");
    return 0;
}
