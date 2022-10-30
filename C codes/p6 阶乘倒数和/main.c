#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 1, count = 1;
    double sum = 1.0,term = 1.0;
    do
    {
        term = term / n;
        sum = sum + term;
        count++;
        n++;
    }while (fabs(term) >= 1e-5);
    printf("e = %f, count = %d\n", sum, count);
    return 0;
}
