
//2. WAP to merge 2 Linked list.  

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node * create(struct node *start);
void display(struct node *start);
struct node * merge(struct node *p, struct node *q, struct node *s);

int main()
{
    struct node *start=NULL, *p, *q,*s=NULL, *start3;
    
    printf("Create Sorted List 1:\n");
    p=create(start);
    printf("List 1:\n");
    display(p);
    printf("\n");
    
    printf("Create Sorted List 2:\n");
    q=create(start);
    printf("List 2:\n");
    display(q);
    printf("\n");
    
    start3=merge(p,q,s);
    printf("Merged Sorted List:\n");
    display(start3);
    
    return 0;
}

struct node * create(struct node *start)
{
    int n, i;
    struct node *temp, *p;
    
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
	{
	    printf("Memory full! Couldn't allocate memory!\n");
	    return NULL;
	}


    printf("Enter info : ");
    scanf("%d", &p->info);
    
    p->next=NULL;
    start=p;
    
    for (i=1;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
	    {
	        printf("Memory full! Couldn't allocate memory!\n");
	        return NULL;
    	}
        printf("Enter info : ");
        scanf("%d", &temp->info);
        temp->next=NULL;
        p->next=temp;
        p=temp;
    }
    
    printf("Linked List created successfully.\n\n");
    return start;
}

void display(struct node *start)
{
    if (start==NULL)
    {
        printf("Linked List empty!\n");
        return;
    }
    
    struct node *p=start;
    
    while (p!=NULL)
    {
        printf("%d\t", p->info);
        p=p->next;
    }
    printf("\n");
}

struct node * merge(struct node *p, struct node *q, struct node *s)
{
    struct node *start3=NULL;
    
    if (p==NULL)
        return q;
 
    if (q==NULL)
        return p;
 
    if (p->info <= q->info)  
    {
        s=p;
        p=p->next;
    }
    else
    {
        s=q;
        q=q->next;
    }
    
    start3=s;
    
    while (p!=NULL && q!=NULL)
    {
        if (p->info <= q->info) 
        {
            s->next=p;
            s=p;
            p=p->next;
        }
        else
        {
            s->next=q;
            s=q;
            q=q->next;
        }
    }
    
    if (p!=NULL)
        s->next=p;
    if (q!=NULL)
        s->next=q;
        
    return start3;
}


