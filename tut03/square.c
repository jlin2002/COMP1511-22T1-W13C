// Print square of specified size using asterisks
// Week 3 Tutorial Problems Q13
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
            printf("*");
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}

