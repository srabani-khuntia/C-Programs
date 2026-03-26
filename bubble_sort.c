
//bubble sort using function
#include <stdio.h>
int sort_asc(int arr[],int size);
int main()
{   
    int n,i;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    sort_asc(arr,n);
  
    printf("Sorted array in ascending order:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    
    printf("\n");
}

int sort_asc(int arr[],int size)
{
    int i,j,temp;
    
    for (i=0;i<size-1;i++)
	{
        for (j=0;j<size-i-1;j++) 
		{
            if (arr[j]>arr[j+1])
			{
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
	}
    return 0;
}
