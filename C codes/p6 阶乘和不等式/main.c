#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    unsigned long n, i, sum = 0, term = 1;
    printf("Please input n :");
    scanf("%lu", &n);
    for (i = 1; sum < n; i++)
    {
        term = term * i ;
        sum = sum + term;

    }

    printf("m <= %lu\n", i - 2);
    return 0;
}
*/
int main()
{
    unsigned long i = 0, n, sum = 0, term = 1;
    printf("Please enter n :");
    scanf("%lu", &n);
    do
    {
      i++;
      term = term * i;
      sum = sum + term;
    }while (sum < n);
    printf("m <= %lu", i - 1);
    return 0;
}
