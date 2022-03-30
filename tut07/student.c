// Struct pointers example

#include <string.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 200

struct student {
    int zID;
    double wam;
    char name[MAX_NAME_LENGTH];
};

int main(void) {
    /*
    int number;
    int *number_ptr = &number;
    *number_ptr = 10;
    */
    struct student stu;
    struct student *stu_pointer = &stu;
    /*
        zID: 5123456
        wam: 74.7
        name: Frankie
    */
    stu_pointer->zID = 5123456;
    stu_pointer->wam = 74.7;
    strcpy(stu_pointer->name, "Frankie");
    printf("zID: %d, wam: %lf, name: %s\n", stu.zID, stu.wam, stu.name);
    return 0;
}
