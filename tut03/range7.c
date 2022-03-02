// Program that prints all numbers divisible by 7 within a certain range
// Week 3 Tutorial Problems Q11
// W13C, March 2022

#include <stdio.h>

int main(void) {
    int start;
    int finish;
    printf("Enter start: ");
    scanf("%d", &start);
    printf("Enter finish: ");
    scanf("%d", &finish);
    
    int i = start;
    while (i <= finish) {
        if (i % 7 == 0) {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}
