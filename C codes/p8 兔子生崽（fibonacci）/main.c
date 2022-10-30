#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12

void Fibonacci(int a[], int n);

int main()
{
    int a[MONTHS];
    Fibonacci(a, MONTHS);
    printf("\nTotal = %d\n", a[MONTHS - 1]);
    return 0;
}

void Fibonacci(int a[], int n)
{
    int i;
    a[0] = 1;
    a[1] = 2;
    for (i = 2; i < MONTHS; i++)
    {
        a[i] =  a[i - 2] + a[i - 1];
    }
    for (i = 0; i < MONTHS; i++)
    {
        printf("%4d", a[i]);
    }
}
