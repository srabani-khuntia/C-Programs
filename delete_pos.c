//to delete an element at the desired position
#include <stdio.h>
int main()
{
    int n,i,pos;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    printf("Enter array elements:\n");
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    printf("Enter position to delete:\n");
    scanf("%d", &pos);
    
    if (pos>n)
        printf("Invalid Position.\n");
        
    else
    {
        for (i=pos-1;i<n-1;i++)
            arr[i]=arr[i+1];
            
        printf("Updated array:\n");
        for (i=0;i<n-1;i++)
            printf("%d\t", arr[i]);
        printf("\n");
    }
}

