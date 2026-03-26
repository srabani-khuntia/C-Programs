

//1. Write a menu-driven program to perform the insert, delete, and Traverse operations on a circular queue Implemented using an array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX], rear=-1, front=-1;

void insert(int item);
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
}

void insert(int item)
{
    if ((rear==MAX-1 && front==0) || front==rear+1)
    {
        printf("Queue Overflow\n");
        return ;
    }

    else
    {
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
    
        else if(rear==MAX-1)
            rear=0;
    
        else
            rear++;
    
        cq[rear]=item;
    }
    return;
}

void delete()
{
    int item;

    if (front==-1 && rear==-1)
    {
        printf("Queue Underflow.\n");
        return;
    }
    
    else
    {
        printf("Deleted element: %d\n",cq[front]);
        
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if (front==MAX-1)
            front=0;
    
        else
            front++;
    }
    return;
}

void display()
{
    int i;

    if (front==-1 && rear==-1)
    {
        printf("Queue empty.\n");
        return;
    }
    else
    {
        printf("Queue is : \n");
        if (front<=rear)
        {
            for (i=front;i<=rear;i++)
                printf("%d\t", cq[i]);
        }

        else if (front>rear)
        {
            for (i=front;i<=MAX-1;i++)
                printf("%d\t", cq[i]);

            for(i=0;i<=rear;i++)
                printf("%d\t", cq[i]);
        }
        
        printf("\n\n");

        return;

    }
}
