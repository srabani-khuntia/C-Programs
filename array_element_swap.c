//swapping elements of given positions in an array

#include <stdio.h>
int main()

{
    int n,i,p1,p2,temp;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter array elements:\n");
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    printf("Enter the two positions to swap:\n");
    scanf("%d%d",&p1,&p2);
    
    temp=arr[p1-1];
    arr[p1-1]=arr[p2-1];
    arr[p2-1]=temp;
    
    
    printf("The updated array is:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    
    printf("\n");
}
