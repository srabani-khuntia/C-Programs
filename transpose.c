
//transpose
#include <stdio.h>
int main()
{
    int i, j,m, n ;
    
    printf ("Enter number of rows and columns:\n");
    scanf("%d%d",&m,&n);
    
    int mat[m][n], mattr[n][m];
   
    printf ("Enter matrix:\n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf ("%d", &mat[i][j]) ;
    }

    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            mattr[i][j]=mat[j][i];
    } 
    
    printf ("The transposed matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d\t" ,mattr[i][j]);
        printf ("\n");
    }
}
