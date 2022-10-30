#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\n");
    printf("-\t -\t -\t -\t -\t -\t -\t -\t -\n");
    for (m = 1; m < 10; m++)
    {
        for (n = 1; n < 10; n++)
        {
            printf("%d\t ", m * n);
        }
        printf("\n");
    }
    return 0;
}
