#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a, b, c, s, area;
    printf("Input a,b,c: ");
    scanf("%f,%f,%f", &a, &b, &c);
    s = (a + b + c) / 2;
    area = (float)sqrt(s * (s - a) * (s - b) * (s - c));
    printf("area = %f\n", area);
    printf("1.0/2.0 = %f\n", 1.0/2.0);
    return 0;
}
