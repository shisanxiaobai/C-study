#include <stdio.h>
#include <stdlib.h>

int IsPrime(int m);

int main()
{
    int m, flag;
    printf("Input number:");
    scanf("%d", &m);
    flag = IsPrime(m);
    if (!flag)
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
    if ( m <= 1)
    {
        return 0;
    }
    for (i = 2; i <= m - 1; i++)
    {
        if (m % i == 0)
        {
            return 0;
        }
    }

}
