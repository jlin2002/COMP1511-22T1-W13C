#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "stack.h"

struct stack {
    struct list *list;
};

struct stack *create_stack() {
    struct stack *new_stack = malloc(sizeof(struct stack));
    new_stack->list = create_list();
    return new_stack;
}

void print_stack(struct stack *stack) {
    print_list(stack->list);
}

void pop(struct stack *stack, char dest[MAX_STR_LENGTH]) {
    pop_front(stack->list, dest);
}

void push(struct stack *stack, char *item) {
    push_head(stack->list, item);
}

int is_empty(struct stack *stack) {
    return peek_index(stack->list, 0) == NULL;
}

void free_stack(struct stack *stack) {
    free_list(stack->list);
    free(stack);
}
