#include <stdio.h>
#include <stdlib.h>

unsigned long Fact(unsigned int n);

int main()
{
    unsigned int n, i;
    printf("Input n(n>0):");
    scanf("%u", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%u! = %lu\n", i, Fact(i));
    }
    return 0;
}

unsigned long Fact(unsigned int n)
{
    unsigned int i;
    unsigned long result = 1;
    for (i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
