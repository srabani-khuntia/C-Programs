// find the largest element in an array.

#include <stdio.h>
int main()

{
    int n,i,lar;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter array elements:\n");
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    lar=arr[0];
    
    for(i=0;i<n;i++)
    {
        if (arr[i]>lar)
            lar=arr[i];
    }
    
    printf("The largest element in the array is %d.\n", lar);
}
