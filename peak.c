
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
		int arr[n], peak[n];
		printf("Enter the elements of the array:\n");
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		if(arr[0]>arr[1])
		{
		    pindex++;
		    peak[0]=arr[0];
		}
			
		for(i=1;i<n-1;i++)
        {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                pindex++;
                peak[pindex]=arr[i];
            }
        }
        
        if (arr[n-1]>arr[n-2]) 
        {
            pindex++;
            peak[pindex]=arr[n-1];
        }
        if (pindex==-1)
            printf("No peak elements present.\n");
        else
        {
            printf("Peak elements:\n");
            for (i=0;i<=pindex;i++)
                printf("%d\t",peak[i]);
            printf("\n");
    	}
	}
	
}
