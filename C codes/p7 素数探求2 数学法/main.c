#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int m);

int main()
{
    int m;
    printf("Input number:");
    scanf("%d", &m);
    if (!IsPrime(m))
    {
        printf("%d is not a prime number\n", m);
    }
    else
    {
        printf("%d is a prime number\n", m);
    }
    return 0;
}

int IsPrime(int m)
{
    int i;
    if (m <= 1) return 0;
    for (i = 2; i <= (int)sqrt(m); i++)
    {
        if (m % i == 0)
            return 0;
    }
    return i;
}
