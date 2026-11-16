#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Queue Overflow! Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into the queue.\n", value);
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    temp = front;
    printf("%d deleted from the queue.\n", temp->data);
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element = %d\n", front->data);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (FRONT to REAR):\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\nQueue operations\n");
        printf("1)Enqueue\t2)Dequeue\t3)Peek\t4)Display\t5)Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
