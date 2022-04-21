#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "stack.h"

#define MAX_STACK_SIZE 2048 

struct stack {
    int size;
    char items[MAX_STACK_SIZE][MAX_STR_LENGTH];
};

struct stack *create_stack() {
    struct stack *new_stack = malloc(sizeof(struct stack));
    new_stack->size = 0;
    return new_stack;
}

void print_stack(struct stack *stack) {
    int i = stack->size - 1;
    while (i >= 0) {
        printf("%s", stack->items[i]);
        i--;
    }
}

void pop(struct stack *stack, char dest[MAX_STR_LENGTH]) {
    strcpy(dest, stack->items[stack->size - 1]);
    stack->size--;
}

void push(struct stack *stack, char *item) {
    strcpy(stack->items[stack->size], item);
    stack->size++;
}

int is_empty(struct stack *stack) {
    return stack->size == 0;
}

void free_stack(struct stack *stack) {
    free(stack);
}
