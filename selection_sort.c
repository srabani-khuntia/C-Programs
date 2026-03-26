    
//Selection sort


#include <stdio.h>
void selection_sort(int arr[], int n);
int main()
{
    int i, n;
    
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements:\n");
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);
        
    selection_sort(arr,n);
    
    printf("The sorted array is :\n");
    
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
        
    printf("\n");

}

void selection_sort(int arr[], int n)
{
    int i,j, sm, temp, smindex; 
    for (i=0;i<n-1;i++)
    {
        smindex=i; 
        
        for (j=i+1;j<n;j++)
        {
            if (arr[j]<arr[smindex])
                smindex=j;
        }
        
        temp=arr[i];
        arr[i]=arr[smindex];
        arr[smindex]=temp;
    }
}
