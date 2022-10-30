#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 1, count = 1;
    float x;
    double sum, term;
    printf("Please input x :");
    scanf("%f", &x);
    sum = x;
    term = x;
    do
    {
        term = -term * x * x / ((n + 1) * (n + 2));
        sum = sum + term;
        n += 2;
        count++;
    }while (fabs(term) >= 1e-5);
    printf("sum = %f, count = %d", sum, count);
    return 0;
}
