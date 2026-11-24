/*
Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
*/

#include <stdio.h>

int main(void) {
    int count;
    if (scanf("%d", &count) != 1 || count < 0) {
        return 1;
    }
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        perror("students.txt");
        return 1;
    }
    char name[100];
    int roll;
    double marks;
    for (int i = 0; i < count; i++) {
        if (scanf("%99s %d %lf", name, &roll, &marks) != 3 ||
            fprintf(file, "%s %d %.17g\n", name, roll, marks) < 0) {
            fclose(file);
            return 1;
        }
    }
    if (fclose(file) != 0) {
        return 1;
    }
    file = fopen("students.txt", "r");
    if (!file) {
        return 1;
    }
    int scanned;
    while ((scanned = fscanf(file, "%99s %d %lf", name, &roll, &marks)) == 3) {
        printf("Name: %s | Roll: %d | Marks: %g\n", name, roll, marks);
    }
    int failed = scanned != EOF || ferror(file);
    fclose(file);
    if (failed) {
        return 1;
    }
    return 0;
}
