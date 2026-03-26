
//reversal of a string

#include <stdio.h>
int main()
{
    int st, en, len_str=0, temp;
    char str[100];
    
    printf("\nEnter string : ");
    scanf("%[^\n]", str);
    
    while (str[len_str]!='\0')
        len_str++;
    
    for(st=0, en=len_str-1; st<en ; st++,en--)
    {
        temp=str[st];
        str[st]=str[en];
        str[en]=temp;
    }
    
    printf("\nThe reversed string is : %s\n", str);
}
