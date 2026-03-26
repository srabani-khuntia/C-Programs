

//sparse matrix to column major triplet

#include <stdio.h>
void triplet(int mat[][10],int r, int c );
void display(int mat[][3],int r, int c);
int main()
{
    int r,c,i,j;
    
    printf("Enter number of rows and columns of the sparse matrix:\n");
    scanf("%d%d", &r,&c);
    
    int sparse[10][10];
    
    printf("Enter matrix elements:\n");
    
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d", &sparse[i][j]);
    }
    
    triplet(sparse,r,c);
    
    return 0;
}

void triplet(int mat[][10], int r, int c)
{
    int i,j,n0=0,ctr=1;
    
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (mat[i][j]!=0)
                n0++;
        }
    }
    
    int triplet[n0+1][3];
    
    triplet[0][0]=c;
    triplet[0][1]=r;
    triplet[0][2]=n0;
    
    for (j=0;j<c;j++)
    {
        for(i=0;i<r;i++)
        {
            if (mat[i][j]!=0)
            {
                triplet[ctr][0]=j;
                triplet[ctr][1]=i;
                triplet[ctr][2]=mat[i][j];
                
                ctr++;
            }
        }
    }
    
    printf("\nColumn major triplet representation of the sparse matrix:");
    
    printf("\n\nC\tR\tV\n\n");
    
    display(triplet,n0+1,3);
    
}

void display(int mat[][3],int r, int c)
{
    int i, j;
    
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
