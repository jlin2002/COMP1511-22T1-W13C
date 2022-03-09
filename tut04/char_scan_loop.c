// Program that reads characters from a user and prints them if they
// are alphabetic letters
// H11A, October 2021

#include <stdio.h>

int is_letter(char c);

int main(void) {
    char c;
    while (scanf(" %c", &c) == 1) {
        if (is_letter(c)) {
            printf("%c\n", c);
        }
    }
    return 0;
}

int is_letter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
