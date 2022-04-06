#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

struct student {
    int zID;
    double mark;
    char name[MAX_LENGTH];
    struct student *next;
};

struct student *create_student(int zID, double mark, char *name);
void print_student(struct student *stu);
void print_last_student(struct student *head);

int main(void) {
    struct student *harry = create_student(5000000, 71.3, "Harry");
    struct student *lucy = create_student(5111111, 62.9, "Lucy");
    struct student *fatima = create_student(5222222, 85.3, "Fatima");
    struct student *carlos = create_student(5333333, 51.6, "Carlos");
    struct student *feng = create_student(5444444, 93.4, "Feng");
    harry->next = lucy;
    lucy->next = fatima;
    fatima->next = carlos;
    carlos->next = feng;
    
    // Print the students in the list to make sure
    // that we've linked up the students correctly!
    struct student *curr = harry;
    while (curr != NULL) {
        print_student(curr);
        curr = curr->next;
    }

    print_last_student(NULL);
    return 0;
}

// Creates and returns a pointer to a student node
struct student *create_student(int zID, double mark, char *name) {
    struct student *stu_p = malloc(sizeof(struct student));
    stu_p->zID = zID;
    stu_p->mark = mark;
    strcpy(stu_p->name, name);
    stu_p->next = NULL;
    return stu_p;
}

// Prints details of a single student
void print_student(struct student *stu) {
    printf("%s has zID %d and a mark of %lf\n",
        stu->name, stu->zID, stu->mark);
}

// Prints the last student in a linked list of students
// Inputs:
//      head: the start of the list of students.
void print_last_student(struct student *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct student *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    printf("The last student: ");
    print_student(curr);
}


