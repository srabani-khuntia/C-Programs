

//1.Write a menu driven program to implement stack using Linked list.

#include <stdio.h>
#include <stdlib.h>

void display();
void push();
void pop();
void peek();

struct node
{
    int info;
    struct node *next;
};
struct node *top=NULL;

int main()
{
    int x;
    
    while(1)
    {
        printf("\nMenu:-\n2. Display\n3. Push\n4. Pop\n5. Peek\n6. Exit\n\n");
        
        printf("Enter choice : ");
        scanf("%d", &x);
        
        switch(x)
        {
            case 2:
                display();
                break;
            case 3:
                push();
                break;
            case 4:
                pop();
                break;
            case 5:
                peek();
                break;
            case 6:
                printf("Program Exited Successfully.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! TRY AGAIN!\n");
        }
    }
    return 0;
}

void display()
{
    if (top==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    
    struct node *p;
    p=top;
    
    printf("Stack is :\n");
    while (p!=NULL)
    {
        printf("%d\n", p->info);
        p=p->next;
    }
}

void push()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL)
	{
	    printf("Memory full! Couldn't allocate memory!\n");
	    return;
	}
	
    printf("Enter info : ");
    scanf("%d", &temp->info);
        
    temp->next=top;
    top=temp;
    return;
}

void pop()
{
    struct node *temp;
    
    if (top==NULL)
    {   
        printf("Stack Underflow!\n");
        return;
    }
    temp=top;
    top=top->next;
    printf("Popped element : %d\n", temp->info);
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Peeked element : %d\n", top->info);
}

