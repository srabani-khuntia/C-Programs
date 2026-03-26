

//concatenation of two strings

#include <stdio.h>
int main()
{
    int i, len_str1=0;
    char str1[100], str2[100];
    
    printf("\nEnter string 1 : ");
    scanf("%[^\n]", str1);
    printf("\nEnter string 2 : ");
    scanf(" %[^\n]", str2);
    
    while (str1[len_str1]!='\0')
        len_str1++;
    
    for(i=0; str2[i]!='\0';i++)
        str1[len_str1+i]=str2[i];
    
    printf("\nThe concatenated string is :\n%s\n", str1);
    
}
