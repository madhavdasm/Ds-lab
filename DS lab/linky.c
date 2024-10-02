#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insert(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* last = *headRef;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// Function to remove repeating nodes from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test removing duplicates from a linked list
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list (sorted for demonstration)
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 5);
    insert(&head, 7);

    printf("Original linked list: ");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("Linked list after removing duplicates: ");
    printList(head);

    return 0;
}

