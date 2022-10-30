#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int m);
void OutputPrimeFactor(int m);

int main()
{
    int m;
    printf("Enter number:");
    scanf("%d", &m);
    if (IsPrime(m))
    {
        printf("%d is a prime number\n", m);
    }
    else
    {
        printf("%d =", m);
        OutputPrimeFactor(m);
    }
    return 0;
}


int IsPrime(int m)
{
    int i,flag = 1;
    if (m <= 1) flag = 0;
    for (i = 2; i <= (int)sqrt(m) && flag; i++)
    {
        if (m % i == 0)
            flag = 0;
    }
    return flag;
}


void OutputPrimeFactor(int m)
{
    int i;
    for (i = 2; i < m; i++)
    {
        if (m % i == 0)
        {
            printf("%d*", i);
            OutputPrimeFactor(m / i);
            return;
        }
    }
    printf("%d", m);
}
