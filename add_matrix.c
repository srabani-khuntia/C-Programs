//addition of matrix
#include <stdio.h>
int main()
{
    int i, j, m,n;
    
    printf ("Enter number of rows and columns:\n");
    scanf("%d%d",&m,&n);
    
   int mat1[m][n], mat2[m][n], mat3[m][n];
   
   printf ("Enter matrix 1:\n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf ("%d", &mat1[i][j]) ;
    }

    printf ("Enter matrix 2:\n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf ("%d", &mat2[i][j]) ;
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            mat3[i][j]=mat1[i][j]+mat2[i][j];
    }
    
    printf ("The added matrix is : \n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t" ,mat3[i][j]);
        printf ("\n");
    }
    
}
