
// func to check prime or composite
#include <stdio.h>
int check_prime(int);

int main()
{
    int n,a;
    printf("Enter a number:\n");
    scanf("%d",&n);
    
    a=check_prime(n);
    
    if (a==-1)
        printf("%d is neither prime nor composite.\n",n);
    else if(a==0)
        printf("%d is composite.\n",n);
    else if(a=1)
        printf("%d is prime.\n",n);
}

int check_prime(int num)
{
    int i;
    
    if (num<0 || num==0 || num==1 )
        return -1;
    else 
    {
        for (i=2;i<num;i++)
        {
            if(num%i==0)
                return 0;
        }
        return 1;
    }
    
}
