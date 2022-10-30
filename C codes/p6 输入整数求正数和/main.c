#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0, n, sum = 0;
    printf("Please enter n:");
    scanf("%d", &n);
    while (n)
    {
        if (n > 0)
        {
         sum = sum + n;
         count++;
        }
       printf("Please enter n:");
       scanf("%d", &n);
    }
    printf("sum = %d, count = %d", sum, count);
    return 0;
}
