// Program that reads in 2 integers from the user
// and prints the larger number
// Joanna Lin, October 2021

#include <stdio.h>

void print_larger(int first_num, int second_num);

int main(void) {
    int first;
    int second;
    scanf("%d%d", &first, &second);
    print_larger(first, second);
    
    return 0;
}

void print_larger(int first_num, int second_num) {
    int larger_num = first_num;
    if (second_num > first_num) {
        larger_num = second_num;
    }
    printf("The larger number is %d\n", larger_num);
}


