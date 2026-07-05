/* WAP to define a C structure named Student (roll_no, name, branch and batch_no) and also to access the structure members using Pointer. */

#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

int main() {
    struct Student s1;

    struct Student *ptr;

    ptr = &s1;

    ptr->roll_no = 101;
    strcpy(ptr->name, "Alex Mercer");
    strcpy(ptr->branch, "Computer Science");
    ptr->batch_no = 2026;

    printf("--- Student Details Information ---\n");
    printf("Roll Number : %d\n", ptr->roll_no);
    printf("Name        : %s\n", ptr->name);
    printf("Branch      : %s\n", ptr->branch);
    printf("Batch No    : %d\n", ptr->batch_no);

    return 0;
}
