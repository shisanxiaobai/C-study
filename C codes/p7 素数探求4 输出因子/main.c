#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int m);


int main()
{
    int m, i, FirstFactor = 1;
    printf("Please input number:");
    scanf("%d", &m);
    if (IsPrime(m))
    {
        printf("No divisor! It is a Prime number\n");
    }
    else
    {
        for (i = 2; i < fabs(m); i++)
        {
            if (m % i == 0)
            {
                if (FirstFactor == 0)
                printf(",");
                printf("%d", i);
                FirstFactor = 0;
            }
        }
        printf("\n");
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
