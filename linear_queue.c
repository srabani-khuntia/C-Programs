
//1. Write a menu-driven program to perform the insert, delete, and Traverse operations on a linear queue Implemented using an array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int q[MAX], rear=-1, front=-1;

void insert();
void delete();
void display();


int main()
{
    int x, item;
    
    while (1)
    {
        printf("\nMenu:-\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
    
        printf("Enter choice : ");
        scanf("%d", &x);
    
        switch(x)
        {
            case 1:
                printf("Enter element to insert : ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nProgram exited successfully.\n");
                exit(0);
            default:
                printf("\nWrong choice entered! Try again!\n");
        }
    }
    
    return 0;
}

void insert(int item)
{
    if (rear==MAX-1)
    {
        printf("Queue Overflow\n");
        return ;
    }
    if(front==-1 && rear==-1)
        front=0;
    
    q[++rear]=item;
    return;
}

void delete()
{
    if (front==-1)
    {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Deleted element: %d\n",q[front++]);
    return;
}

void display()
{
    int i;

    if (front==-1 && rear==-1 || front==rear+1)
    {
        printf("Queue empty.\n");
        return;
    }
    printf("Queue is : \n");
    
    for (i=front;i<=rear;i++)
        printf("%d\t",q[i]);
    printf("\n\n");
}

