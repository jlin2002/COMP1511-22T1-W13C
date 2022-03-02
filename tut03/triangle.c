// Print triangle of specified size using asterisks and bars
// Week 3 Tutorial Problems Q14
// W13C, March 2022
#include <stdio.h>

int main(void) {
    printf("Enter size: ");
    int size;
    scanf("%d", &size);
    
    int row = 0;
    while (row < size) {
        int col = 0;
        while (col < size) {
            if (col <= row) {
                printf("*");
            } else {
                printf("-");
            }
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}

