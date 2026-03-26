
//3. WAP to evaluate any arithmetic expression written in postfix notation using a stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
int s[MAX];
int top=-1;

void push(int);
int pop();
int evaluate(char[]);

int main()
{
	char str[100];
	
    printf("Enter a postfix expression:\n");
    scanf("%[^\n]", str);
    
    printf("Evaluation result: %d\n", evaluate(str));
    
    return 0;
}

void push(int item)
{
    if (top==MAX -1)
        return;
        
    s[++top] = item;
    return;
}

int pop()
{
    if (top == -1)
        return 0;

    return s[top--];
}

int evaluate(char str[])
{
    int i, op1,op2;
    
    for (i=0; str[i]!='\0';i++)
    {
        if (str[i]>='0' && str[i]<='9')
            push(str[i]-'0');
        
        else if (str[i]==' ')
            continue;
            
        else
        {
            op2=pop();
            op1=pop();
            
            if (str[i]=='+')
                 push(op1+op2);
            else if (str[i]=='-')
                push(op1-op2);
            else if (str[i]=='*')
                push (op1*op2);
            else if (str[i]=='/')
                push(op1/op2);
            else
            {
                printf("Invalid operators present.\n");
                exit(1);
            }
        }
    }
    
    return pop();
}
