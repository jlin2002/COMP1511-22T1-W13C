// Program that counts up from 1 to a given number
// W13C, March 2022

#include <stdio.h>

int main(void) {
    printf("Enter finish: ");
    int finish;
    scanf("%d", &finish);
    
    int i = 1;
    while (i <= finish) {
        printf("%d\n", i);
        i++; 
    }
    return 0;
}
