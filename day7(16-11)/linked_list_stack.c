#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into the stack.\n", value);
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    temp = top;
    printf("%d popped from the stack.\n", temp->data);
    top = top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element = %d\n", top->data);
}

void display()
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (TOP to BOTTOM):\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\nStack operations\n");
        printf("1)Push\t2)Pop\t3)Peek\t4)Display\t5)Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to Push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting the program......\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
