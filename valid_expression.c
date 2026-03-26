
//4. WAP to check the validity of any expression containing nested parenthesis using a stack.

#include <stdio.h>

#define MAX 50
char s[MAX];
int top=-1;

void push(char);
char pop();
int pair(char, char);
int isvalid(char[]);

int main()
{
    char str[100];
    
    printf("Enter an expression:\n");
    scanf("%[^\n]", str);
    
    if (isvalid(str))
        printf("Expression has balanced parentheses.\n");
    else
        printf("Invalid Expression!\n");
        
    return 0;
}

void push(char item)
{
    if (top==MAX -1)
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

int isvalid(char str[])
{
    int i, item;
    
    for (i=0;str[i]!='\0';i++)
    {
        if (str[i]=='[' || str[i]=='{' || str[i]=='(')
            push(str[i]);
        
        else if (str[i]==']' || str[i]=='}' || str[i]==')')
        {
            if (pair(pop(),str[i])==0)
                return 0;
        }
    }
    
    return top==-1;
}

int pair(char a, char b)
{
    return ((a=='[' && b==']') || (a=='{' && b=='}') || (a=='(' && b==')'));
}

