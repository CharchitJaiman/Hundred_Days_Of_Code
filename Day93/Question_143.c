/*
Find and print the student with the highest marks.
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
        if (next.marks > best.marks) {
            best = next;
        }
    }
    printf("Topper: %s (Marks: %g)\n", best.name, best.marks);
    return 0;
}
