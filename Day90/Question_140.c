/*
Define a struct with enum Gender and print person's gender.
*/

#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };
struct Person {
    enum Gender gender;
};

int main(void) {
    struct Person person;
    char input[20];
    if (scanf(" Gender=%19s", input) != 1) {
        return 1;
    }
    if (strcmp(input, "MALE") == 0) {
        person.gender = MALE;
    } else if (strcmp(input, "FEMALE") == 0) {
        person.gender = FEMALE;
    } else if (strcmp(input, "OTHER") == 0) {
        person.gender = OTHER;
    } else {
        return 1;
    }
    const char *names[] = {"Male", "Female", "Other"};
    puts(names[person.gender]);
    return 0;
}
