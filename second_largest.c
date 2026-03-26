//find the second largest element in an array

#include <stdio.h>
int main()
 {
    int n,i,lar, lar2;
	
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    if (n < 2)
        printf("Array must have at least two elements.\n");

    else 
	{
		int arr[n];
		printf("Enter the elements of the array: ");
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		if(arr[0]<arr[1])
		{
			lar2=arr[0];
			lar=arr[1];
		}
		else
		{
			lar2=arr[1];
			lar=arr[0];
		}
		

		for (i = 2; i < n; i++) 
		{
			if (arr[i] > lar)
			{
				lar2 = lar;
				lar= arr[i]; 
			} 
			else if (arr[i] > lar2 && arr[i] < lar) 
			{
				lar2= arr[i]; 
			}
		}

		if (lar==lar2) 
			printf("There is no second largest element in the array.\n");
		else 
			printf("The second largest element is %d.\n", lar2);

    }
}
