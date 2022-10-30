#include <stdio.h>
#include <stdlib.h>

int IsPrefect(int m);

int main()
{
    int m;
    printf("Input number :");
    scanf("%d", &m);
    if (IsPrefect(m))
    {
        printf("%d is a prefect number\n", m);
    }
    else
    {
        printf("%d is not a prefect number\n", m);
    }
    return 0;
}


int IsPrefect(m)
{
    int i;
    int total = 0;
    if (m < 1) return 0;
    for (i = 1; i < m; ++i)
    {
        if ( m % i == 0)
            total += i;
    }
    return total == m ? 1 : 0;
}
