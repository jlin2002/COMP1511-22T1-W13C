// Program that echoes command line arguments
#include <stdio.h>
#include <ctype.h>

// Change the main function so that we can access command line arguments.
// Loop through command line arguments (excluding the first) to print them out
int main(int argc, char *argv[]) {
    int i = 1;
    while (i < argc) {
        printf("argv[%d] = ", i);
        int j = 0;
        while (argv[i][j] != '\0') {
            printf("%c", toupper(argv[i][j]));
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
