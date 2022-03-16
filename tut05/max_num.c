#include <stdio.h>
int *max_num(int *a, int *b);

int main(void) {
    printf("Enter 2 values: ");
    int a, b;
    scanf("%d %d", &a, &b);
    int *max = max_num(&a, &b);
    printf("The larger value is %d\n", *max);
    return 0;
}

// Returns the address of the greater of two integers stored at the addresses
int *max_num(int *a, int *b) {
    if (*a < *b) {
        return b;
    } else {
        return a;
    }
}
