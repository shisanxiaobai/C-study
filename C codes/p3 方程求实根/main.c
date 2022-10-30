#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, disc, p, q;
    printf("please enter the coefficients a, b, c :");
    scanf("%f, %f, %f", &a, &b, &c);
    disc = b * b - 4 * a * c;
    if (disc > 0)
    {
        p = - b / (2 * a);
        q = sqrt(disc) / (2 * a);
        printf("%7.4f, %7.4f\n", p+q, p-q);
    }
    else
    {
        printf("No real roots\n");
    }
    return 0;
}
