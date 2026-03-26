//finding the peak element
#include <stdio.h>
int main()
{
    int n,i,pindex=-1;
	
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    
    if (n<2)
        printf("Array must have at least two elements.\n");
    else 
	{
		int arr[n], peak[n/2];
		printf("Enter the elements of the array:\n");
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		if(arr[0]>arr[1])
			peak[0]=arr[0];
		else
		    peak[0]=arr[1];

        for(i=1;i<n-1;i++)
        {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                pindex++;
                arr[i]=peak[pindex];
            }
        }
        
        printf("Peak elements:\n");
        for (i=0;i<=pindex;i++)
            printf("%d\t",peak[i]);
        printf("\n");
	}	    
}
