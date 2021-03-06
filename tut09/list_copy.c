#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *copy(struct node *head);
struct node *create_node(int data);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);
void free_list(struct node *head);

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *head_copy = copy(head);
    printf("head at %p: ", head);
    print_list(head);
    printf("head_copy at %p: ", head_copy);
    print_list(head_copy);

    free_list(head);
    free_list(head_copy);
    return 0;
}

//////////////////////////////////////////////////////////////////////
// Create a copy of the list given
// The head of the copy is returned.
struct node *copy(struct node *head) {
    struct node *head_copy = NULL;
    struct node *curr_copy = NULL;
    struct node *curr = head;
    while (curr != NULL) {
        struct node *new_node = create_node(curr->data);
        if (head_copy == NULL) {
            head_copy = new_node;
        } else {
            curr_copy->next = new_node;
        }
        curr_copy = new_node;
        curr = curr->next;
    }
    return head_copy;
}

// Creates a node storing the given data value
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// print linked list with addresses of each node
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d (at %p)", n->data, n);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}

// frees all memory associated with a linked list starting from head.
void free_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
