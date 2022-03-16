// Initialises the values of a 7 x 7 2D array to 1 and prints them
#include <stdio.h>

#define SIZE 7

void initialise_grid(int grid[SIZE][SIZE]);
void print_grid(int grid[SIZE][SIZE]);

int main(void) {
    int grid[SIZE][SIZE];
    initialise_grid(grid);
    print_grid(grid);
    
    // Having a 2D array allows us to store state.
    grid[2][3] = 9;
    printf("\n");
    print_grid(grid);
}

void initialise_grid(int grid[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int column = 0;
        while (column < SIZE) {
            grid[row][column] = 1;
            column = column + 1;
        }
        row = row + 1;
    }
}

void print_grid(int grid[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int column = 0;
        while (column < SIZE) {
            printf("%d ", grid[row][column]);
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
}
