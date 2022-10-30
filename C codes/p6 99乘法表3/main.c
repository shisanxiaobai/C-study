#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, k;
    for (m = 1; m < 10; m++)
    {
        for (k = 1; k <= 4 * m - 4; k++)
        {
            printf(" ");
        }
        for (n = m; n < 10; n++)
        {
            printf("%4d", m * n);
        }
        printf("\n");
    }
    return 0;
}
