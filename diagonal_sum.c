
//sUm of diagonals
#include <stdio.h>
int main()
{
    int i, j,m, n , dia=0;
    
    printf ("Enter number of rows and columns:\n");
    scanf("%d%d",&m,&n);
    
    int mat[m][n];
   
    printf ("Enter matrix:\n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf ("%d", &mat[i][j]) ;
    }

    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if (i==j)
                dia+=mat[i][j];
    } 
    
    printf ("The sum of the diagonal elements is %d.\n", dia);
    
}
