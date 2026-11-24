/*
Return a structure containing top student's details from a function.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;
static int read_student(Student *student) {
    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && (isspace(ch) || ch == ','));
    if (ch == EOF) {
        return 0;
    }
    ungetc(ch, stdin);
    return scanf("%99s %d %lf", student->name, &student->roll_no, &student->marks) == 3;
}
static Student higher_scoring(Student first, Student second) {
    return second.marks > first.marks ? second : first;
}

int main(void) {
    int count;
    if (scanf(" %d students:", &count) != 1 || count < 1) {
        return 1;
    }
    Student best;
    if (!read_student(&best)) {
        return 1;
    }
    for (int i = 1; i < count; i++) {
        Student next;
        if (!read_student(&next)) {
            return 1;
        }
        best = higher_scoring(best, next);
    }
    printf("Top Student: %s | Roll: %d | Marks: %g\n", best.name, best.roll_no, best.marks);
    return 0;
}
