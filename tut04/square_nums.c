// Program that writes square numbers to an array and prints them
// W13C, March 2022

#include <stdio.h>
#define SIZE 7

void write_square_nums(int length, int array[SIZE]);
void print_array(int length, int array[SIZE]);

int main(void) {
    int square_nums[SIZE];
    write_square_nums(SIZE, square_nums);
    print_array(SIZE, square_nums);
    return 0;
}

// Writes square numbers to an array
void write_square_nums(int length, int array[SIZE]) {
    int i = 0;
    while (i < length) {
        array[i] = (i + 1) * (i + 1);
        i++;
    }
}

// Prints array elements, separated by new lines.
void print_array(int length, int array[SIZE]) {
    int i = 0;
    while (i < length) {
        printf("%d\n", array[i]);
        i++;
    }
}
