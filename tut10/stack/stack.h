#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STR_LENGTH 1024

// Creates a stack and returns it
struct stack *create_stack();
// Prints items in the stack, from the most recently added to least recently added
void print_stack(struct stack *stack);
// Removes item most recently added to the stack, and copies the data into the dest string
void pop(struct stack *stack, char dest[MAX_STR_LENGTH]);
// Adds item to the stack
void push(struct stack *stack, char *item);
// Returns 1 if stack is empty, 0 otherwise.
int is_empty(struct stack *stack);
// Frees the stack
void free_stack(struct stack *stack);

#endif
