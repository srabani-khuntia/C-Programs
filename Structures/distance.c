//WAP to define a structure DISTANCE having members as kms, and metres. Define a user-defined function ADDDISTANCE () which will receive two structure variables as its arguments and will return a structure variable. The ADDDISTANCE () will add two distance values.

#include <stdio.h>
struct DISTANCE ADDDISTANCE(struct DISTANCE,struct DISTANCE);
struct DISTANCE
{
    int kms, metres;
};

int main()
{
    int i;
    struct DISTANCE d[2], res;

    for (i=0; i<2;i++)
    {
        printf("\nDistance %d:-\n", i+1);
        printf("kms=");
        scanf("%d", &d[i].kms);
        printf("m=");
        scanf("%d", &d[i].metres);
    }
    
    res = ADDDISTANCE(d[0],d[1]);
    
    printf("\nThe resultant distance is %d km %d m.\n", res.kms, res.metres);
    
    return 0;
}

struct DISTANCE ADDDISTANCE( struct DISTANCE a, struct DISTANCE b)
{
    struct DISTANCE res;
    
    res.kms = a.kms + b.kms;
    res.metres = a.metres + b.metres;
    
    if (res.metres>=1000)
    {
        res.kms+=res.metres/1000;
        res.metres=res.metres%1000;
    }
    
    return res;
}  
