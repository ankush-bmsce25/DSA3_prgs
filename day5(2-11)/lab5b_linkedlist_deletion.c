/*WAP to Implement Singly Linked List with following
operations
a. Create a linked list.
b. Deletion of the first element, specified element and last
element in the list.
c. Display the contents of the linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
    int data;
    struct Node *next;
};

// Delete a node from the beginning
void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty. Deletion not possible!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete a node from a specified position
void deletePosition(struct Node **head, int position)
{
    struct Node *temp, *prev;
    int i;
    if (*head == NULL)
    {
        printf("List is empty. Deletion not possible!\n");
        return;
    }
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    // If the first node is to be deleted
    if (position == 1)
    {
        deleteBeginning(head);
        return;
    }
    temp = *head;
    prev = NULL;
    // Traverse to the specified position
    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
// Delete a node from the end
void deleteEnd(struct Node **head)
{
    struct Node *temp, *prev;

    if (*head == NULL)
    {
        printf("List is empty. Deletion not possible!\n");
        return;
    }
    // If there is only one node
    if ((*head)->next == NULL)
    {
        temp = *head;
        *head = NULL;

        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    temp = *head;
    prev = NULL;
    // Traverse to the last node
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Create the linked list by inserting nodes at the end
void createList(struct Node **head, int n)
{
    struct Node *newNode, *temp;
    int i, value;
    int values[n];

    printf("Enter data of n nodes : ", n);
    for (int i=0; i<n; i++)
        scanf("%d",&values[i]);

    for (i = 0; i < n; i++)
    {

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        newNode->data = values[i];
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            temp = *head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

int main()
{
    struct Node *head = NULL;
    int n, choice, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    createList(&head, n);

    printf("\nOriginal linked list:\n");
    display(head);

    do
    {
        printf("\n\n1. Delete from Beginning");
        printf("\t2. Delete from Specified Position");
        printf("\t3. Delete from End");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deleteBeginning(&head);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletePosition(&head, position);
            break;

        case 3:
            deleteEnd(&head);
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
    }
    while (choice != 5);

    // Release any remaining nodes
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
