
/*1. Write a menu-driven program to implement the following operation on a Double-linked list:
A. Creation
B. Traversal
C. Insertion at the beginning
D. Insertion at the end
E. Insertion at any location
F. Delete the first node
G. Delete the last node
H. Deletion from any location
I. Delete the given item*/

#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_loc();
void delete_begin();
void delete_end();
void delete_loc();
void delete_item();

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start=NULL;

int main()
{
    int x;
    
    while(1)
    {
        printf("\nMenu:-\n1. Create\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert at any location\n6. Delete at beginning\n7. Delete at end\n8. Delete at any location\n9. Delete an item\n10. Exit\n\n");
        
        printf("Enter choice : ");
        scanf("%d", &x);
        
        switch(x)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_loc();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_loc();
                break;
            case 9:
                delete_item();
                break;
            case 10:
                printf("Program Exited Successfully.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! TRY AGAIN!\n");
        }
    }
    return 0;
}

void create()
{
    int n, i;
    struct node *temp, *p;
    
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    
    p=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter info : ");
    scanf("%d", &p->info);
    
    p->prev=NULL;
    p->next=NULL;
    start=p;
    
    for (i=1;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter info : ");
        scanf("%d", &temp->info);
        
        temp->prev=p;
        temp->next=NULL;
        p->next=temp;
        p=temp;
    }
    
    printf("Linked List created successfully.\n");
    return;
}

void display()
{
    if (start==NULL)
    {
        printf("Linked List empty!\n");
        return;
    }
    
    struct node *p1=start, *p2;
    
    printf("Linked List in forward direction is :\n");
    while (p1!=NULL)
    {
        printf("%d\t", p1->info);
        p2=p1;
        p1=p1->next;
    }
    printf("\n");
    
    printf("Linked List in backward direction is :\n");
    while (p2!=NULL)
    {
        printf("%d\t", p2->info);
        p2=p2->prev;
    }
    printf("\n");
}

void insert_begin()
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
    
    temp->prev=NULL;
    temp->next=NULL;
    
    if (start!=NULL)
	    start->prev=temp;
    temp->next=start;
    start=temp;
    return;
}

void insert_end()
{
    struct node *temp, *p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL)
	{    
	    printf("Memory full! Couldn't allocate memory!\n");
	    return;
	}
	printf("Enter info : ");
    scanf("%d", &temp->info);
    
    temp->prev=NULL;
    temp->next=NULL;
    
    if (start==NULL)
    {
        start=temp;
        return;
    }
        
    while (p->next!=NULL)
        p=p->next;
    
    p->next=temp; 
    temp->prev=p;
}

void insert_loc()
{
    int pos,ctr=1;
    struct node *temp, *p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL)
    {
	    printf("Memory full! Couldn't allocate memory!\n");
	    return;
    }
    
    printf("Enter info : ");
    scanf("%d", &temp->info);
        
    printf("Enter position : ");
    scanf("%d", &pos);
    
    temp->prev=NULL;
    temp->next=NULL;
    
    if (pos==1)
    {
        temp->prev=NULL;
        temp->next=start;
        if (start!=NULL)
            start->prev=temp;
        start=temp;
        return;
    }
    
    while (p!=NULL && ctr<pos-1)
    {
        p=p->next;
        ctr++;
    }
    
    if (p==NULL)
    {
        printf("Entered position is out of bound!\n");
        return;
    }
    
    temp->prev=p;
    temp->next=p->next;
    if (p->next!=NULL)
        p->next->prev=temp;
    p->next=temp;
    
    return;
}

void delete_begin()
{
    struct node *temp=start;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    start=start->next;
    if (start!=NULL)
        start->prev=NULL;
        
    printf("Deleted item : %d\n", temp->info);
    free(temp);
}

void delete_end()
{
    struct node *temp=start, *p=NULL;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }

    if (start->next==NULL)
    {
        printf("Deleted item : %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }
    while (temp->next!=NULL)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=NULL;
    
    printf("Deleted item : %d\n", temp->info);
    free(temp);
    return;
}

void delete_loc()
{
    struct node *p, *temp=start;
    int pos, ctr=1;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    printf("Enter position : ");
    scanf("%d", &pos);
    
    if (pos == 1)
    {
        start = start->next;
		if (start!=NULL)
			start->prev=NULL;
        
        printf("Deleted item : %d\n", temp->info);
        free(temp);
        return;
    }
    
    while (temp!=NULL && ctr<pos)
    {
        p=temp;
        temp=temp->next;
        ctr++;
    }
    
    if (temp==NULL)
    {    
        printf("Position out of bound!\n");
        return;
    }
    p->next = temp->next;
	if (temp->next!=NULL)
		temp->next->prev=p;
	
    printf("Deleted item : %d\n", temp->info);
    free(temp);
    return;
}

void delete_item()
{
    struct node *temp=start, *p=NULL;
    int i;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    printf("Enter item to delete : ");
    scanf("%d", &i);
    
    if (start->info==i)
    {
        start = start->next;
		if (start!=NULL)
			start->prev=NULL;
        
        printf("Deleted item : %d\n", temp->info);
        free(temp);
        return;
    }
    
    while (temp!=NULL)
    {
        if (temp->info==i)
        {
            p->next=temp->next;
            if (temp->next!=NULL)
                temp->next->prev=p;
                
            printf("Deleted item : %d\n", temp->info);
            free(temp);
            return;
        }
        p=temp;
        temp=temp->next;
    }
    
    printf("Item not in Linked List!\n");
}
