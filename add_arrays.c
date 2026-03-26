// find element wise addition result of two arrays
#include <stdio.h>
int main()

{
    int n,i;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    int arr1[n], arr2[n], arr3[n];
    
    printf("Enter elements of array 1:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr1[i]);
        
    printf("Enter elements of array 2:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr2[i]);
        
    for(i=0;i<n;i++)
        arr3[i]=arr1[i]+arr2[i];
    
    printf("Element wise addition result:\n");
    
    for(i=0;i<n;i++)
        printf("%d\t", arr3[i]);
        
    printf("\n");
    
}
