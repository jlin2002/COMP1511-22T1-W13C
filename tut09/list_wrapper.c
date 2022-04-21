// Program that demonstrates a wrapper around the head of a linked list

#include <stdio.h>
#include <stdlib.h>

// Our wrapper around head
struct linked_list {
    struct node *head;
};

struct node {
    struct node *next;
    int          data;
};

struct node *create_node(int data);
void prepend(int data, struct linked_list *list);
void print_list(struct linked_list *list);
void free_list(struct linked_list *list);
struct linked_list *create_list();

int main(void) {
    struct linked_list *list = create_list();
    prepend(1, list);
    prepend(2, list);
    prepend(3, list);

    // We should have the list 3 -> 2 -> 1 -> X
    // Print list to make sure
    print_list(list);

    // Free list to prevent memory leaks
    free_list(list);
    return 0;
}

struct linked_list *create_list() {
    struct linked_list *new_list = malloc(sizeof(struct linked_list));
    new_list->head = NULL;
    return new_list;
}

// Prepends a node storing the give data value to a list and returns the new
// head
void prepend(int data, struct linked_list *list) {
    struct node *new_head = create_node(data);
    new_head->next = list->head;
    list->head = new_head;
}

// Creates a node storing the given data value
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Prints a list
void print_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("X\n");
}

// Free all memory associated with the list
void free_list(struct linked_list *list) {
    struct node *curr = list->head;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    // TODO: What have we missed?
    free(list);
}

