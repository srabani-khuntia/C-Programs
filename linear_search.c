//search using function
#include <stdio.h>
int search(int num,int arr[],int size);
int main()
{   
    int n,i,x,a;
    
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    printf("Enter an element to search:\n");
    scanf("%d",&x);
    
    a=search(x, arr, n);
    
    if (a==1)
        printf("%d found.\n",x);
    else if(a==0)
        printf("%d not found!\n",x);
}

int search(int num,int arr[], int size)
{   
    for(int i=0;i<size;i++)
    {
        if (arr[i]==num)
            return 1;
    }
    return 0;
}
