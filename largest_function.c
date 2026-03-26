

//design a function that wil return largest among 2 entered nums this function to find largest among 3 munbers
#include <stdio.h>
int largest(int,int);

int main()
{
    int n1, n2, n3, lar;

    printf("Enter number 1, number 2, number 3:\n"); 
    scanf("%d %d %d", &n1, &n2,&n3);

    lar=largest(n1, largest(n2, n3));

    printf("The largest among %d, %d and %d is %d.\n", n1, n2, n3, lar);
}

int largest(int a, int b)
{
    if (a>=b)
        return a;
    else
        return b;
}
