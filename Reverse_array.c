
//reverse the elements of an array

#include <stdio.h>
int main()
{
    int n,i,st,en,temp;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter array elements:\n");
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    printf("Original array:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");
        
    for(st=0,en=n-1;st<en;st++,en--)
    {
        temp=arr[st];
        arr[st]=arr[en];
        arr[en]=temp;
    }
    
    printf("Reversed array:\n");
     for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");
}       
