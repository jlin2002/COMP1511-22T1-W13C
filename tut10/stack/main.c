#include <stdio.h>

#include "stack.h"

#define ADD 'a'
#define EAT 'e'
#define PRINT 'p'

void handle_command(struct stack *pancake, char command);

int main(void) {
    struct stack *pancakes = create_stack();

    char command;
    while (scanf(" %c", &command) == 1) {
        handle_command(pancakes, command);
    }

    free_stack(pancakes);
    return 0;
}

// Handles a command
// Important commands:
// - 'a' <name>: place new pancake onto pancake stack
// - 'e':        eat top pancake
// - 'p':        print pancake stack
void handle_command(struct stack *pancakes, char command) {
    char pancake_name[MAX_STR_LENGTH];
    if (command == ADD) {
        // Get pancake name
        fgets(pancake_name, MAX_STR_LENGTH, stdin);
        // Push pancake onto stack
        push(pancakes, pancake_name);
        printf("Added: %s", pancake_name);
    } else if (command == EAT) {
        // Check whether stack is empty and if so, do not pop
        if (is_empty(pancakes)) { 
            printf("The customer has reached the plate! You cannot eat that!\n");
        } else {
            pop(pancakes, pancake_name);
            printf("The customer has eaten %s", pancake_name);
        }
    } else if (command == PRINT) {
        print_stack(pancakes);
    }
    return;
}
