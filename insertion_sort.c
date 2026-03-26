
//Insertion sort

#include <stdio.h>
void insertion_sort(int arr[], int n);
int main()
{
    int i, n;
    
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    insertion_sort(arr,n);
    
    printf("The sorted array is:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    
    printf("\n"); 
}

void insertion_sort(int arr[], int n)
{
    int i,j, key;
    for (i=1;i<n;i++)
    {
        key=arr[i]; 
        
        j=i-1;
        
        while (j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        
        arr[j+1]=key;
    }
}
