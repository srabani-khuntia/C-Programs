
//WAP to define a structure STUDENT having members as name, roll_ no, branch, and CGPA. Enter the details of 5 students. Display the details of the student having the highest CGPA.

#include <stdio.h>

struct STUDENT
{
    char name[50];
    int roll_no;
    char branch[20];
    float CGPA;
};

int main()
{
    struct STUDENT s[5];
    int i;
    float h;
    
    for (i=0;i<5; i++)
    {
        printf("\nEnter details of student %d :-", i+1);
        printf("\nName : ");
        scanf(" %[^\n]", &s[i].name);
        printf("Roll no.: ");
        scanf(" %d", &s[i].roll_no);
        printf("Branch : ");
        scanf(" %[^\n]", &s[i].branch);
        printf("CGPA : ");
        scanf("%5f", &s[i].CGPA);
    }
    
    h=s[0].CGPA;
    
    for(i=1; i<5; i++)
    {
        if (s[i].CGPA>h)
            h=s[i].CGPA;
    }
    
    printf("\nStudents with the highest CGPA %5.2f are: \n\n", h);
    
    for (i=0;i<5;i++)
    {
        if (s[i].CGPA==h)
        {
            printf("Name : %s\n", s[i].name);
            printf("Roll no.: %d\n", s[i].roll_no);
            printf("Branch : %s\n\n", s[i].branch);
        }
    }
    
    return 0;
}
