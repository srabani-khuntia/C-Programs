//sum of array elements using function
#include <stdio.h>
int sum(int arr[],int size);
int main()
{   int n,i;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Array:\n");
    for (i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");
    printf("The sum of all elements in the array is %d.\n", sum(arr,n));
}
int sum(int arr[], int size)
{   int i, sum=0;
    for(i=0;i<size;i++)
        sum+=arr[i];
    return sum;
}
