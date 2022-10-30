#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int n, sum = 0, count = 0;
    printf("Please enter number: ");
    scanf("%ld", &n);
    while (n > 0)
    {
        sum = sum + n;
        printf("Please enter number: ");
        scanf("%ld", &n);
        count++;
    }
    printf("sum = %ld, count = %ld", sum, count);
    return 0;
}
