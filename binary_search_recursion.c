
//binary search using recursion

#include <stdio.h>
int binary_search(int [], int l, int u, int x); 
void bubble_sort(int arr[], int n);

int main() 
{
    int i, n, x;
    
    printf("Enter number of elements:\n"); 
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n"); 
    for (i=0;i<n;i++) 
        scanf("%d", &arr[i]);

    printf("Enter element to search:\n"); 
    scanf("%d", &x);

    bubble_sort(arr,n);

    if (binary_search(arr,0,n-1,x)==1) 
        printf("%d found.\n", x);
    else
        printf("%d not found!\n", x);
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

int binary_search(int arr[], int l, int u, int x)
{
    int m;
    
    if (l > u) 
        return 0;
        
    m=l+(u-l)/2;
    
    if (x==arr[m])
        return 1;
    if (x<arr[m])
        return binary_search(arr,l,m-1,x);
    return binary_search(arr,m+1,u,x);

}
