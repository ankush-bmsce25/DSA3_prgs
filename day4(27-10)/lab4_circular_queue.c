//WAP to simulate the working of a circular queue of integers using an array. Provide the following operations:
//Insert, Delete & Display The program should print appropriate messages for queue empty and queue overflow conditions
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int cirq[MAX];
int F = -1, R = -1;
void enqueue()
{

    int ele;
    printf("\nEnter the element :- ");
    scanf("%d", &ele);
    if (F == -1 && R == -1){
        F = R = 0;
        cirq[R] = ele;
    }
    else if (F == 0 && R == MAX - 1 || R == F - 1)
    {
        printf("\nCircular queue full!!\n\n");
        return;
    }
    else if (R == MAX - 1 && F != 0)
    {
        R = (R + 1) % MAX;
        cirq[R] = ele;
    }
    else
    {
        cirq[++R] = ele;
    }
    printf("Element entered : %d\n\n",ele);
}
void dequeue()
{
    int ele;
    if (F == -1)
    {
        printf("\nCircular queue empty!!\n\n");
        return;
    }
    else if (F == R)
    {
        ele = cirq[F];
        F = R = -1;
    }
    else if (F == MAX - 1)
    {
        ele = cirq[F];
        cirq[F]=0;
        F = (F + 1) % MAX;
    }
    else
    {
        ele = cirq[F];
        cirq[F]=0;
        F++;
    }
    printf("\nElement removed is %d\n\n", ele);
}
void display()
{
    if (F == -1)
    {
        printf("\nQueue empty.Insert elements\n\n");
        return;
    }
    printf("\nCircular display :- \n");
    for(int i=F;;i=(i+1)%MAX){
        printf("%d\t",cirq[i]);
        if(i==R) break;
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("Operations:-\n");
    while (1)
    {
        printf("1)Enqueue\t2)Dequeue\t3)Display\t4)Exit\nEnter choice :- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option!!\n\n");
            break;
        }
    }
    return 0;
}
