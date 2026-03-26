
//norm
#include <stdio.h>
#include <math.h>

float norm(int mat[][], int m, int n)
{
    int sum=0;
    
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            sum+= pow(mat[i][j],2);
    }
    
    return sqrt(sum);
}

int main()
{
    int m,n,i,j;
    
    printf("Enter number of rows and columns:\n");
    scanf("%d%d", &m,&n);
    
    int mat[m][n];
    
    printf("Enter matrix elements:\n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    
    printf("The norm of the matrix is %f", norm(mat,m,n));
}
