#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node definition
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/*
 * Create new node (using data as input)
 */
Node* create_node(int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

/*
 * Insert Node at the beginning
 */
void push(Node **head_ref, Node *new_node) {
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/*
 * Insert Node at the end
 */
void append(Node **head_ref, Node *new_node) {
    // If list is empty, the node is inserted at the beginning
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // If list is not empty, we look for the last node
    Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

/*
 * Insert Node after a giving position
 */
void insert_after(Node *prev_node, Node *new_node) {
    if (prev_node == NULL) {
        printf("The previous node cannot be NULL\n");
        return;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/*
 * Display list content in the standard output
 */
void print_list(Node *head) {
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

/*
 * Delete list (free memory)
 */
void clear_list(Node **head_ref) {
    Node *current = *head_ref;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

/*
 * Make a copy of a list
 */
Node* clone_list(Node *head) {
    Node *current = head;
    Node *new_list = NULL;
    Node *tail = NULL;

    while (current != NULL) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        memcpy(new_node, current, sizeof(Node));

        if (new_list == NULL) {
            push(&new_list, new_node);
            tail = new_list;
        } else {
            push(&(tail->next), new_node);
            tail = tail->next;
        }
        current = current->next;
    }

    return new_list;
}

/*
 * Delete node by value
 */
void delete_node(Node **head_ref, int key) {
    Node *tmp = *head_ref, *prev;

    // The node to be deleted is the first position
    if (tmp != NULL && tmp->data == key) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    // If not, we find the matching node (if any)
    while (tmp != NULL && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    // If not found, nothing is done
    if (tmp == NULL) {
        return;
    }

    // If found, the previous node is connected to the next
    // and then, the memory of the matching node is released
    prev->next = tmp->next;
    free(tmp);
}

int main() {
    Node *head = NULL;

    // Push 6
    Node *node_6 = create_node(6);
    push(&head, node_6);
    printf("Insert 6 at the beginning. Linked list is:");
    print_list(head);

    // Push 7
    Node *node_7 = create_node(7);
    push(&head, node_7);
    printf("Insert 7 at the beginning. Linked list is:");
    print_list(head);

    // Push 1
    Node *node_1 = create_node(1);
    push(&head, node_1);
    printf("Insert 1 at the beginning. Linked list is:");
    print_list(head);

    // Delete 7
    delete_node(&head, 7);
    printf("Delete node with value 7. Linked list is:");
    print_list(head);

    // Append 4
    Node *node_4 = create_node(4);
    append(&head, node_4);
    printf("Insert 4 at the end. Linked list is:");
    print_list(head);

    // Insert 8
    Node *node_8 = create_node(8);
    insert_after(head->next, node_8);
    printf("Insert 8 after second node. Linked list is:");
    print_list(head);

    // Copy list
    Node *head_copy = clone_list(head);
    printf("Copy of linked list:");
    print_list(head_copy);

    // Delete original list
    clear_list(&head);
    printf("Original linked list after deleting:");
    print_list(head);

    // Delete copied list
    clear_list(&head_copy);
    printf("Copy of linked list after deleting:");
    print_list(head_copy);

    return 0;
}
