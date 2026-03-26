
//multiplication
#include <stdio.h>
int main()
{
    int i, j,k, m1,n1, m2,n2;
    
    printf ("Enter number of rows and columns for matrix 1:\n");
    scanf("%d%d",&m1,&n1);
    
    printf ("Enter number of rows and columns for matrix 2:\n");
    scanf("%d%d",&m2,&n2);
    
    if (n1==m2)
    {
        int mat1[m1][n1], mat2[m2][n2], mat3[m1][n2];
   
        printf ("Enter matrix 1:\n");
    
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
                scanf ("%d", &mat1[i][j]) ;
        }

        printf ("Enter matrix 2:\n");
    
        for(i=0;i<m2;i++)
        {
            for(j=0;j<n2;j++)
                scanf ("%d", &mat2[i][j]) ;
        }



        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
            {
                mat3[i][j]=0;
                for(k=0;k<n1;k++)
                    mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    
        printf ("The multiplied matrix is:\n");
        for(i=0;i<m1;i++)
        {
            for(j=0;j<n2;j++)
                printf("%d\t" ,mat3[i][j]);
            printf ("\n");
        }
    }
    
    else
        printf("Matrix multiplication not possible. Number of columns of matrix 1 must be equal to number of rows of matrix 2.\n");
        
}

