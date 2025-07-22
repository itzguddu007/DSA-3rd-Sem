#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    printf("Enter the no of employees: ");
    scanf("%d",&n);
    struct Employee e[n];
    struct Employee *ptr;
    ptr = e;

    printf("Enter details of 3 employees:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &(ptr + i)->id);
        printf("Name: ");
        scanf(" %[^\n]", (ptr + i)->name);
        printf("Salary: ");
        scanf("%f", &(ptr + i)->salary);
    }

    float maxSalary = (ptr)->salary;
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((ptr + i)->salary > maxSalary) {
            maxSalary = (ptr + i)->salary;
            maxIndex = i;
        }
    }

    printf("\nEmployee with highest salary:\n");
    printf("ID: %d\n", (ptr + maxIndex)->id);
    printf("Name: %s\n", (ptr + maxIndex)->name);
    printf("Salary: %.2f\n", (ptr + maxIndex)->salary);

    return 0;
}
