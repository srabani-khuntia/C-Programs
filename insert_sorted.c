// inserting an element at its correct position in an sorted array

#include <stdio.h>
int main()

{
    int n,i,x;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter element to insert:\n");
    scanf("%d", &x);
    
    printf("Enter array elements:\n");
    
    int arr[n+1];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    for(i=n-1;i>=0;i--)
    {
        if (x<arr[i])
            arr[i+1]=arr[i];
        
        else
        {
            arr[i+1]=x;
            break;
        }
    }
    
    printf("Sorted array in ascending order:\n");
    for (i=0;i<n+1;i++)
        printf("%d\t", arr[i]);
    
    printf("\n");
}
