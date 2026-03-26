
 //2. WAP to reverse any string using a stack

#include <stdio.h>
#include <string.h>

#define MAX 10

char s[MAX];
int top = -1;

void push(char);
char pop();

int main()
{
    int i;
    char str[10];

    printf("Enter string:\n");
    scanf("%10[^\n]", str);
    
    printf("The entered string is :\n%s\n", str);

    for (i=0;i<strlen(str);i++)
        push(str[i]);
    
    for (i=0;i<strlen(str);i++)
        str[i]=pop();
        
    printf("The reversed string is :\n%s\n", str);
    
    return 0;
}

void push(char item)
{
    if (top ==MAX -1)
        return;
        
    s[++top] = item;
    return;
}

char pop()
{
    if (top == -1)
        return '\0';

    return s[top--];
}

