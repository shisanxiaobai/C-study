#include <stdio.h>
#include <stdlib.h>

int LCM(int a, int b);

int main()
{
    int a, b, x;
    printf("Please enter a and b:");
    scanf("%d%*c%d", &a, &b);
    x = LCM(a, b);
    if (x != -1)
    {
        printf("Least common Multiple of %d and %d is %d\n", a, b, x);
    }
    else
    {
        printf("Input  error\n");
    }
return 0;
}

int LCM(int a, int b)
{
    int i;
    if (a <= 0 || b <= 0)
    {
        return -1;
    }
    for (i = 1; i <b; i++)
    {
        if (i * a % b == 0)
            return i * a;
    }
    return a * b;
}
