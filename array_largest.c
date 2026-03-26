
//largset using function
#include <stdio.h>
int lar(int arr[],int size);
int main()
{   
    int n,i;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter array elements:\n");
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    printf("The largest element in the array is %d.\n", lar(arr,n));
}

int lar(int arr[], int size)
{   
    int lar, i;
    
    lar=arr[0];
    for(i=0;i<size;i++)
    {
        if (arr[i]>lar)
            lar=arr[i];
    }
    return lar;
}
