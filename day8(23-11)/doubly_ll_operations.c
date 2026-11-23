#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* 1. Create a NEW list using a for loop */
void create() {
    int n, value, i;
    struct node *newnode, *last = NULL;

    /* If an old list exists, delete it first so we start fresh */
    while (head != NULL) {
        struct node *old = head;
        head = head->next;
        free(old);
    }

    printf("How many nodes do you want? ");
    scanf("%d", &n);
    printf("Enter value for %d nodes :- ", n);
    for (i = 1; i <= n; i++) {

        scanf("%d", &value);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = last;      /* new node points back to the previous last node */

        if (head == NULL)
            head = newnode;        /* first node becomes head */
        else
            last->next = newnode;  /* old last node points forward to the new node */

        last = newnode;            /* new node is now the last node */
    }

    printf("List created with %d nodes.\n", n);
}

/* 2. Insert a new node to the left of a given node (by value) */
void insert_left(int target, int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found.\n", target);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode; /* inserting before the first node */

    temp->prev = newnode;
    printf("Inserted %d to the left of %d.\n", value, target);
}

/* 3. Delete a node by value */
void delete_value(int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; /* deleting the first node */

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted %d.\n", value);
}

/* 4. Display the list */
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Create\t");
        printf("2. Insert to the left\t");
        printf("3. Delete by value\t");
        printf("4. Display\t");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("Insert to the left of which value? ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                insert_left(target, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_value(value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
