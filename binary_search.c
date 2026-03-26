//binary search

#include <stdio.h>
int binary_search(int [], int n, int x); 
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

    if (binary_search(arr, n, x)==1) 
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

int binary_search(int arr[], int n, int x)
{
    int l,u, m;

    l=0;
    u=n-1;

    while(l<=u)
    {
        m=(l+u)/2;
        
        if (x==arr[m])
            return 1;
        else if (x<arr[m])
            u=m-1;
        else if(x>arr[m])
            l=m+1;
    }

    return 0;
}
