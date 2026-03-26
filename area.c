
//find the area of a circle using function

#include <stdio.h>
#include <math.h>

float circle_area(float);

int main()
{
    float rad;
    
    printf("Enter radius of the circle in cm:\n");
    scanf("%f",&rad);
    
    printf("The area of the circle is %f cm\n", circle_area(rad));
}


float circle_area(float rad)
{
    return M_PI*pow(rad,2);
}
