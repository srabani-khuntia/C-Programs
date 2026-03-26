
//design a function to find afctoial of a number
#include <stdio.h>
int factorial(int);
int main()
{
    int n;
    printf("Enter a number:\n"); 
    scanf("%d", &n);
    
    if (n<0)
        printf("The factorial of a negative number is not defined.\n");
    else
        printf("The factorial of %d is %d.\n", n, factorial(n));
}

int factorial(int num)
{
    int p=1,i;
    for (i=1;i<=num;i++)
        p*=i;
    return p;
}
