#include <stdio.h>
#include <stdlib.h>

int Age (int n);

int main()
{
    int n;
    printf("Input total persons:");
    scanf("%d", &n);
    printf("n = %d\n", Age(n));
    return 0;
}

int Age (int n)
{
    int age;
    if (n == 1)
    {
        age = 10;
    }
    else
    {
        age = Age(n - 1) + 2;
    }
    return age;
}
