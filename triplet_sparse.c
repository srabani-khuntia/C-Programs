// column major triplet to sparse

#include <stdio.h>
void sparse(int mat[][3],int n0 );
void display(int r, int c, int mat[r][c]);
int main()
{
    int r,c,n0,i,j;
    
    printf("Enter number of non zero elements:\n");
    scanf("%d",&n0);
    
    int triplet[n0+1][3];
    
    printf("Enter the triplet matrix:\n\n");
    printf("C\tR\tV\n\n");
    
    for (i=0;i<n0+1;i++)
    {
        for(j=0;j<3;j++)
            scanf("%d", &triplet[i][j]);
    }
    
    sparse(triplet,n0);
    
    return 0;
}

void sparse(int mat[][3], int n0)
{
    int i,j,r,c;
    
    r = mat[0][1];
    c = mat[0][0];
    
    int sparse[r][c];

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
            sparse[i][j]=0;
    }
    
    for (i=1;i<n0+1;i++)
        sparse[mat[i][1]][mat[i][0]]=mat[i][2];
        
    printf("\nThe original sparse matrix is:\n\n");
    
    display(r,c,sparse);
    
}

void display(int r, int c, int mat[r][c])
{
    int i, j;
    
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}


