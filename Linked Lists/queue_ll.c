

//2.Write a menu driven program to implement queue using Linked list.

#include <stdio.h>
#include <stdlib.h>

void display();
void insert();
void delete();

struct node
{
    int info;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;

int main()
{
    int x;
    
    while(1)
    {
        printf("\nMenu:-\n2. Display\n3. Insert\n4. Delete\n5. Exit\n\n");
        
        printf("Enter choice : ");
        scanf("%d", &x);
        
        switch(x)
        {
            
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete();
                break;
            case 5:
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
    if (f==NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    
    struct node *p=f;
    
    printf("Queue is :\n");
    while (p!=NULL)
    {
        printf("%d\t", p->info);
        p=p->next;
    }
}

void insert()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL)
	{
	    printf("Memory full! Couldn't allocate memory!\n");
	    return;
	}
	
    printf("Enter element : ");
    scanf("%d", &temp->info);
        
    temp->next=NULL;
    
    if (f == NULL)
        f = r = temp;
    else
    {
        r->next = temp;
        r = temp;
    }
}

void delete()
{
    struct node *temp;
    
    if (f==NULL)
    {   
        printf("Queue Underflow!\n");
        return;
    }
    temp=f;
    f=f->next;
    
    if (f == NULL)
        r = NULL;
        
    printf("Deleted element : %d\n", temp->info);
    free(temp);
}
