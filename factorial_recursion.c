//factorial uding recursion
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
    if(num==0)
        return 1;
    else 
        return num*factorial(num-1);
}
