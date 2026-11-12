/*
Define a structure Student with name, roll_no, and marks, then read and print one student's data.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int roll_no;
    double marks;
} Student;
static void print_student(Student student) {
    printf("Name: %s | Roll: %d | Marks: %g\n", student.name, student.roll_no, student.marks);
}

int main(void) {
    Student student;
    if (scanf(" Name: %99[^\n]\n Roll: %d\n Marks: %lf", student.name, &student.roll_no,
              &student.marks) != 3) {
        return 1;
    }
    print_student(student);
    return 0;
}
