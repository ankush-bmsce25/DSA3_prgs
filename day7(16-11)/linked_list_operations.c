#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList()
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i, value;

    printf("How many elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ",n);
    for (i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = arr[i];
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n\n");
}

struct node *concat(struct node *h1, struct node *h2)
{

    struct node *ptr;

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    ptr = h1;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = h2;
    return h1;
}

struct node *reverseList(struct node *head)
{

    struct node *pre, *cur, *nextNode;

    if (head == NULL || head->next == NULL)
        return head;

    pre = head;
    cur = head->next;
    pre->next = NULL;

    while (cur != NULL)
    {
        nextNode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextNode;
    }
    return pre;
}

void sortList(struct node *head)
{
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    int choice;
    struct node *head;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Concatenate two linked list\n");
        printf("2. Reverse a linked list\n");
        printf("3. Sort a linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n---Concatenation---\n");
            struct node *h1=createList();
            printf("List 1 : ");
            display(h1);
            struct node *h2=createList();
            printf("List 2 : ");
            display(h2);
            head=concat(h1,h2);
            printf("Concatenated list : ");
            display(head);
            break;

        case 2:
            printf("\n---Reversing---\n");
            head = createList();
            printf("Original list: ");
            display(head);
            head = reverseList(head);
            printf("Reversed list: ");
            display(head);
            break;

        case 3:

            printf("\n---Sorting---\n");
            head = createList();
            printf("Original list: ");
            display(head);
            sortList(head);
            printf("Sorted list: ");
            display(head);
            break;

        case 4:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    while (choice != 4);

    return 0;
}
