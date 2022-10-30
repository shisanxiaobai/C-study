#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 1, count = 0;
    double sum = 0, PI, term, sign = 1;
    do
    {
        term = sign / n;
        sum = sum + term;
        count++;
        sign = -sign;
        n += 2;
    }while (fabs(term) >= 1e-4);
    PI = 4 * sum;
    printf("¦Ð = %f, count = %d\n", PI, count);
    return 0;
}
