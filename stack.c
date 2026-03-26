
//1. Write a menu-driven program to perform the PUSH, POP, and Traverse operations on a stack Implemented using an array.

#include <stdio.h>

#define MAX 5

int s[MAX];
int top = -1;

void push(int);
void pop();
void peek();
void display();

int main()
{
    int x, item;
        
    while(1)
    {
        printf("\nMenu:-\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &item);
                push(item);
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
                printf("\nProgram exited successfully.\n");
                exit(0);
                
            default:
                printf("\nInvalid choice, please try again!\n");
        }

    }

    return 0;
}

void push(int item)
{
    if (top == MAX -1)
    {
        printf("\nStack Overflow!\n");
        return;
    }
    s[++top] = item;
    return;
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        return;
    }
    printf("%d popped out from stack.\n", s[top--]);
    return;
}

void peek ()
{
    if (top==-1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    
    printf("\nPeeked %d from stack.\n", s[top]);
    return;
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    printf("\nStack elements are:\n\n");
    for ( i = top; i >= 0; i--)
        printf("%d\n", s[i]);
        
    return;
}
