
// column major triplet transpose

#include <stdio.h>
void transpose(int mat[][3],int n0 );
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
    
    transpose(triplet,n0);
    
    return 0;
}

void transpose(int mat[][3], int n0)
{
    int i,j,r,c,ctr=1;
    
    r = mat[0][1];
    c = mat[0][0];
    
    int trans[n0+1][3];
    
    trans[0][0]=r;
    trans[0][1]=c;
    trans[0][2]=mat[0][2];

    for (j=0;j<c;j++)
    {
        for (i=1;i<n0+1;i++)
        {
            if (mat[i][1]==j)
            {
                trans[ctr][0]=j;
                trans[ctr][1]=mat[i][0];
                trans[ctr][2]=mat[i][2];
                
                ctr++;
            }
        }
    }
    
    printf("\nTransposed Matrix:");
    
    printf("\n\nR\tC\tV\n\n");
    display(n0+1,3,trans);
    
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
