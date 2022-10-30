#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, i, n;
    long sum = 0, term = 0;
    printf("input a, n :");
    scanf("%d%*c%d", &a, &n);
    for (i = 1; i <= n; i++)
    {
        term = term * 10 + a;
        sum = sum + term;
    }
    printf("sum = %ld", sum);
    return 0;
}
