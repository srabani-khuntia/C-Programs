#include <stdio.h>

void ToLower(char);

int main()
{
    char str[1000];
    printf("Enter a string:\n");
    scanf("%[^\n]", str);
    
    ToLower(str);
    
    printf("The updated string is:\n%s",str);
}

void ToLower(char s)
{
    int *p, i;
    
    for (p=&s;*p!='\0';p++)
    {
        if (*p>=65 && *p<=90)
            *p+=32;
    }
}
