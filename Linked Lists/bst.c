
/*Write a menu-driven program to perform the following operations on a BST:
a. Insert
b. Delete
c. Search
d. FindMax
e. FindMin
f. Pre-order Traversal
g. In-order Traversal
h. Post-order Traversal*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *l;
	int info;
	struct node *r;
};
struct node *root=NULL;

void insert();
void delete();
void case1(struct node *, struct node *);
void case2(struct node *, struct node *);
void case3(struct node *, struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void max();
void min();
void search();

int main()
{
	int x;

	while (1)
	{
		printf("\nMenu:\n\n1. Insert\n2. Delete\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Find Maximum\n7. Find Minimum\n8. Search\n9. Exit\n\n");

        	printf("Enter choice: ");
        	scanf("%d", &x);

        	switch(x)
		{
			case 1:
				insert();
				break;
			case 2:
			    delete();
			    break;
			case 3:
				if (root==NULL)
					printf("Tree Empty!\n");
				else
			    {
			        preorder(root);
			        printf("\n");
			    }
				break;
			case 4:
				if (root==NULL)
					printf("Tree Empty!\n");
				else
				{
				    inorder(root);
				    printf("\n");
				}
				break;
			case 5:
				if (root==NULL)
					printf("Tree Empty!\n");
				else
				{
				    postorder(root);
	                printf("\n");
	            }
	            break;
			case 6:
				max();
				break;
			case 7:
				min();
				break;
			case 8:
				search();
				break;
			case 9:
				printf("Program exited successfully.\n");
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}	
	return 0;
}

void insert()
{
	struct node *temp, *p=root, *pn;
	int i;

	temp=(struct node *)malloc(sizeof(struct node));

	if (temp==NULL)
	{
		printf("Memory full! Couldn't allocate memory!\n");
	    return;
	}
	
	printf("Enter info : ");
	scanf("%d", &i);

	temp->info=i;
	temp->l=NULL;
	temp->r=NULL;

	if (root==NULL)
	{
	    root=temp;
	    return;
	}
		
	while (p!=NULL)
	{
		pn=p;
	
		if (i < p->info)
			p=p->l;
			
		else if (i > p->info)
			p=p->r;
				
		else
		{
			printf("Duplicate element is not allowed.\n");
			return;
		}
	
	}
	
	if (p==NULL)
	{
		if (i< pn->info)
			pn->l=temp;
		else 
			pn->r=temp;
	}
}

void delete()
{
	struct node *p=root,*pn=NULL;
	int i;

	if(root == NULL)
	{
	    printf("Tree Empty!\n");
        return;
	}
	
	printf("Enter item to delete\n");
	scanf("%d",&i);

	while(p != NULL)
	{
		if(p->info == i)
			break;
		
		pn=p;
		
		if(i < p->info)
			p=p->l;
		else
			p=p->r;
	}
	
	if(p == NULL)
	{
		printf("Item not found!\n");
	    return;
	}
		
	printf("Deleted item : %d\n",p->info);

	if((p->l!= NULL) && (p->r!= NULL))
	{
	    case3(pn,p);
		return;
	}
		
	if((p->l== NULL) && (p->r == NULL))
	{
	    case1(pn,p); 
        return;
	}
		
	case2(pn,p); 
	
}

void case1(struct node *pn, struct node *p)
{
	printf("Deleted value : %d\n",p->info);

	if(p == NULL)
	{
		root = NULL;
		free(p);
		return;
	}

	if(p->info < pn->info)
		pn->l=NULL;
	else
		pn->r= NULL;

	free(p);
}

void case2(struct node *pn, struct node *p)
{
	struct node *c;

	if(p->l!= NULL)
		c=p->l;
	else
		c= p->r;
	
	printf("Deleted value : %d\n",p->info);

	if(pn == NULL)
	{
		root = c;
		free(p);
		return;
	}
	
	if(p == pn->l)
		pn->l= c;
	else
		pn->r = c;
	
	free(p);
}

void case3(struct node *pn, struct node *p)
{
	struct node *pp=p->r,*ppn=p;

	while(pp->l!= NULL)
	{
		ppn = pp;
		pp = pp->l;
	}
	
	p->info = pp->info;
	
	if(pp->r!= NULL)
		case2(ppn,pp);
	else
		case1(ppn,pp);

}

void preorder(struct node *temp)
{
	if (temp!=NULL)
	{
		printf("%d\t", temp->info);
		preorder(temp->l);
		preorder(temp->r);
	}
}

void inorder(struct node *temp)
{
	if (temp!=NULL)
	{
		inorder(temp->l);
		printf("%d\t", temp->info);
		inorder(temp->r);
	}
}

void postorder(struct node *temp)
{
	if (temp!=NULL)
	{
		postorder(temp->l);
		postorder(temp->r);
		printf("%d\t", temp->info);
	}
}

void max()
{
	struct node *temp=root;

	if(root == NULL)	
		printf("Tree Empty!\n");
	
	else
	{		
		while(temp->r!= NULL)
			temp = temp->r;
		
		printf("Largest element of the tree is %d\n",temp->info);
	}
}

void min()
{
	struct node *temp=root;

	if(root == NULL)	
		printf("Tree Empty\n");

	else
	{
		while(temp->l!= NULL)
			temp = temp->l;
		
		printf("Smallest element of the tree is %d\n",temp->info);
	}
}

void search()
{
	struct node *temp=root;
	int i;

	if(root == NULL)
    {
		printf("Tree Empty!\n");
	    return;
    }
	printf("Enter the item to search : ");
	scanf("%d",&i);

	while(temp!=NULL)
	{
		if(temp->info == i)
		{
			printf("Item found.\n");
			return;
		}

		if(i < temp->info)
			temp = temp->l;
			
		else
			temp = temp->r;
	}

	if(temp == NULL)
		printf("Item not found!\n");
}
