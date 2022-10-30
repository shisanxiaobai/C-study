#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6

int main()
{
    float a, b, c, s, p;
    printf("please input a,b,c: ");
    scanf("%f,%f,%f", &a, &b, &c);
    if(a + b > c && a + c > b && b + c > a)
    {
        p = (a + b + c)/2.0;
        s = sqrt(p * (p - a) * (p - b)* (p - c));
        printf("s = %f\n", s);
    }
    else
    {
        printf("It is not a triangle\n");
    }
    return 0;
}
