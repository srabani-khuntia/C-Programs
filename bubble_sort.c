//Bubble sort

#include <stdio.h>
void bubble_sort(int arr[], int n);
int main()
{
    int i, n;
    
    printf("Enter number of elements:\n"); 
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements:\n"); 
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr,n);

    printf("The sorted array is :\n");
    
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
        
    printf("\n");

}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
 
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
