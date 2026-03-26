

/*Write a menu-driven program to implement the following operation on a single Circular linked list:
a. Creation
b. Traversal
c. Insertion at the beginning
d. Insertion at the end
e. Insertion at any location
f. Insert after a given item
f. Delete the first node
g. Delete the last node
h. Deletion from any location
g. Delete the given item*/

#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_loc();
void insert_after();
void delete_begin();
void delete_end();
void delete_loc();
void delete_item();

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

int main()
{
    int x;
    
    while(1)
    {
        printf("\nMenu:-\n1. Create\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert at any location\n6. Insert after an item\n7. Delete at beginning\n8. Delete at end\n9. Delete at any location\n10. Delete an item\n11. Exit\n\n");
        
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
                insert_after();
                break;
            case 7:
                delete_begin();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                delete_loc();
                break;
            case 10:
                delete_item();
                break;
            case 11:
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
    if(p==NULL)
	{    
	    printf("Memory full! Couldn't allocate memory!\n");
	    return;
	}
    
    printf("Enter info : ");
    scanf("%d", &p->info);
    
    start=p;
    p->next=start;
    
    for (i=1;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
	    {    
	        printf("Memory full! Couldn't allocate memory!\n");
	        return;
    	}
    
        printf("Enter info : ");
        scanf("%d", &temp->info);
        temp->next=start;
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
    
    struct node *p=start;
    
    printf("Linked List is :\n");
    
    do
    {
        printf("%d\t", p->info);
        p=p->next;
    }
    while (p!=start);
    
    printf("\n");
    return;
}

void insert_begin()
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
    
    if (start == NULL)
    {
        temp->next = temp;
        start = temp;
        return;
    }
    
    while (p->next != start)
        p = p->next;
        
    temp->next=start;
    p->next=temp;
    start=temp;
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
    
    if (start == NULL)
    {
        temp->next = temp;
        start = temp;
        return;
    }
        
    while (p->next!=start)
        p=p->next;
    
    p->next=temp;   
    temp->next=start;
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
    
    if (pos==1)
    {
        if (start == NULL)
        {
            temp->next = temp;
            start = temp;
            return;
        }
        
        while (p->next != start)
            p = p->next;
            
        temp->next=start;
        p->next = temp;
        start=temp;
        return;
    }
    
    while (p->next!=start && ctr<pos-1)
    {
        p=p->next;
        ctr++;
    }
    
    if (ctr<pos-1)
    {
        printf("Entered position is out of bound!\n");
        return;
    }
    temp->next=p->next;
    p->next=temp;
}

void insert_after()
{
    struct node *temp, *p = start;
    int i;
    
    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter item after which to insert: ");
    scanf("%d", &i);

    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory full! Couldn't allocate memory!\n");
	    return;
    }

    printf("Enter info: ");
    scanf("%d", &temp->info);
    
    do
    {
        if (p->info == i)
        {
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    } while (p != start);

    printf("Item not found in the list!\n");
    free(temp);
}

void delete_begin()
{
    struct node *temp=start, *p=start;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    if (start->next == start)
    {
        printf("Deleted item : %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }
    
    while (p->next != start)
        p = p->next;

    p->next = start->next;
    start=start->next;
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

    if (start->next == start)
    {
        printf("Deleted item : %d\n", start->info);
        free(start);
        start = NULL;
        return;
    }
    while (temp->next!=start)
    {
        p=temp;
        temp=temp->next;
    }
        
    p->next=start;
    
    printf("Deleted item : %d\n", temp->info);
    free(temp);
}

void delete_loc()
{
    struct node *p=NULL, *temp=start;
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
        if (start->next == start)
        {
            printf("Deleted item: %d\n", start->info);
            free(start);
            start = NULL;
            return;
        }

        while (p->next != start)
            p = p->next;

        temp = start;
        p->next = start->next;
        start = start->next;
        
        printf("Deleted item: %d\n", temp->info);
        free(temp);
        return;
    }
    
    while (ctr < pos)
    {
        ctr++;
        p = temp;
        temp = temp->next;

        if (temp == start)
        {
            printf("Position out of bound!\n");
            return;
        }
    }
    p->next = temp->next;
    printf("Deleted item : %d\n", temp->info);
    free(temp);
}

void delete_item()
{
    struct node *temp=start, *p=start;
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
        if (start->next == start)
        {
            printf("Deleted item: %d\n", start->info);
            free(start);
            start = NULL;
            return;
        }
        
        while (p->next != start)
            p = p->next;

        p->next = start->next;
        start = start->next;
        
        printf("Deleted item: %d\n", temp->info);
        free(temp);
        return;
    }
    
    do
    {
        p = temp;
        temp = temp->next;

        if (temp->info == i)
        {
            p->next = temp->next;
            printf("Deleted item: %d\n", temp->info);
            free(temp);
            return;
        }
    }
    while (temp != start);

    printf("Item not in Linked List!\n");
}
