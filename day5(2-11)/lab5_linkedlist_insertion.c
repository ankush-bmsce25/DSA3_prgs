/*WAP to Implement Singly Linked List with following
operations
a. Create a linked list.
b. Insertion of a node at first position, at any position
and at end of list.
Display the contents of the linked list.*/


#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Insert at the beginning
void insertBeginning(struct Node **head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at a specified position
void insertMiddle(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Position 1 means beginning
    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;

    // Traverse to the node before the position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the list
void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, position;

    do {
        printf("\n\n1. Insert at Beginning");
        printf("\t2. Insert at Middle/Position");
        printf("\t3. Insert at End");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertMiddle(&head, value, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
