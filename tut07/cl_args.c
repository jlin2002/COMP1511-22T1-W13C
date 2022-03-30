// Program that echoes command line arguments
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    while (i < argc) {
        int j = 0;
        while (argv[i][j] != '\0') {
            printf("argv[%d][%d] = %c, ", i, j, argv[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
