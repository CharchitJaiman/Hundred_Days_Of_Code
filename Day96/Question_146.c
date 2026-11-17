/*
Create Employee structure with nested Date structure for joining date and print details.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;
typedef struct {
    char name[100];
    int id;
    Date joined;
} Employee;

int main(void) {
    Employee employee;
    if (scanf(" Employee: %99s | ID: %d | Joining Date: %d %d %d", employee.name, &employee.id,
              &employee.joined.day, &employee.joined.month, &employee.joined.year) != 5) {
        return 1;
    }
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", employee.name, employee.id,
           employee.joined.day, employee.joined.month, employee.joined.year);
    return 0;
}
