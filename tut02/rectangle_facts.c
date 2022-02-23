// A program that prints facts about a rectangle of dimensions specified by the
// user
// W13C, February 2022

#include <stdio.h>
#define MAX_LEN 45000

int main(void) {
    int width;
    int height;
    printf("Please enter width and height of rectangle: ");
    // Take input from user
    scanf("%d %d", &width, &height);
    
    int lengths_are_valid = 0 <= width && width <= MAX_LEN 
        && 0 <= height && height <= MAX_LEN;
    if (!lengths_are_valid) {
        printf("Please enter positive lengths less than %d\n", MAX_LEN);
        return 1;
    }
    
    int area = width * height;
    int perimeter = 2 * (width + height);
    printf("Width: %d, Height: %d\n", width, height);
    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", perimeter);

    return 0;
}
