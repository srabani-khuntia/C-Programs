
/*. Write a menu-driven program to implement the following operation on a single linked list:
a. Creation
b. Traversal
c. Insertion at the beginning
d. Insertion at the end
e. Insertion at any location
f. Delete the first node
g. Delete the last node
h. Deletion from any location
i. Sorting
j. Searching
k. Reversing*/

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
void sort();
void search();
void reverse();

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
        printf("\nMenu:-\n1. Create\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert at any location\n6. Delete at beginning\n7. Delete at end\n8. Delete at any location\n9. Sort\n10. Search\n11. Reverse\n12. Exit\n\n");
        
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
                sort();
                break;
            case 10:
                search();
                break;
            case 11:
                reverse();
                break;
            case 12:
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
    struct node *temp, *new;
    
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    
    new=(struct node *)malloc(sizeof(struct node));
    
    printf("Enter info : ");
    scanf("%d", &new->info);
    
    new->next=NULL;
    start=new;
    
    for (i=1;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter info : ");
        scanf("%d", &temp->info);
        temp->next=NULL;
        new->next=temp;
        new=temp;
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
    
    struct node *p;
    p=start;
    
    printf("Linked List is :\n");
    while (p!=NULL)
    {
        printf("%d\t", p->info);
        p=p->next;
    }
    printf("\n");
    return;
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
        
    while (p->next!=NULL)
        p=p->next;
    
    p->next=temp;   
    temp->next=NULL;
    return;
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
        temp->next=start;
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
    temp->next=p->next;
    p->next=temp;
    return;
}

void delete_begin()
{
    struct node *temp;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    temp=start;
    start=start->next;
    printf("Deleted item : %d\n", temp->info);
    free(temp);
}

void delete_end()
{
    struct node *temp=start, *p;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
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
    printf("Deleted item : %d\n", temp->info);
    free(temp);
    return;
}

void sort()
{
    int i;
    struct node *p, *temp=start, *min;
    
    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    if (start->next == NULL)
    {
        printf("Linked List too short to sort!\n");
        return;
    }
    while (temp->next!=NULL)
    {
        min=temp;
        p=temp->next;
        
        while (p!=NULL)
        {
            if (min->info > p->info)
                min=p;
                
            p=p->next;
        }
        
        if (min!=temp)
        {
            i=min->info;
            min->info=temp->info;
            temp->info=i;
        }
        temp=temp->next;
    }
    return;
}

void search()
{
    struct node *p=start;
    int x;
    
    printf("Enter element to search : ");
    scanf("%d", &x);
 
    while (p!=NULL)
    {
        if (p->info==x)
        {
            printf("%d found.\n", x);
            return;
        }
        p=p->next;
    }
    printf("%d not found.\n", x);
    return;
}

void reverse()
{
    struct node *prev, *p, *temp;

    if (start==NULL)
    {   
        printf("Linked List empty!\n");
        return;
    }
    
    prev=NULL;
    p=start;
    while (p!=NULL)
    {
        temp=p->next;
        p->next=prev;
        prev=p;
        p=temp;
    }
    start=prev;
    return;
}
