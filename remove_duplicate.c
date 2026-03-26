
//removing duplicate elements
#include <stdio.h>
int main()
{
    int n,i,j,k;
	
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    
	int arr[n];
	printf("Enter the elements of the array:\n");
	for (i=0; i<n; i++)
	    scanf("%d", &arr[i]);
	
	for (i=0; i<n-1;i++)
	{
	    for (j=i+1;j<n;j++)
	    {
	        if (arr[i]==arr[j])
            {
                for(k=j;k<n-1;k++)
                    arr[k]=arr[k+1];
                    
                n--;
                j--;
            }
	    }
	    
	}
	
	printf("Updated array:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");
    
}
