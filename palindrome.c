

// func to check palindrome

#include <stdio.h>
int check_palindrome(int);

int main()
{
    int n,a;
    printf("Enter a number:\n");
    scanf("%d",&n);
    
    a=check_palindrome(n);
    
    if (a==1)
        printf("%d is a palindrome number.\n",n);
    else if(a==0)
        printf("%d is not a palindrome number.\n",n);
}

int check_palindrome(int num)
{
    int org,rem,rev=0;
    org=num;
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    
    if (rev==org)
        return 1;
    else
        return 0;
   
}
