#include <stdio.h>
#include <stdlib.h>

int magic (int m);

int main()
{
    int m, ret;
    printf("Please input sum:");
    scanf("%d", &m);
    ret = magic(m);
    if (ret == -1)
    {
        printf("The sum you calculated is wrong\n");
    }
    else
    {
        printf("your guess number is %d\n", ret);
    }
    return 0;
}

int magic(int m)
{
    int a, b, c, n;
    for (a = 1; a < 10; a++)
    {
        for (b = 0; b < 10; b++)
        {
            for (c = 0; c < 10; c++)
            {
                n = 122 * a + 212 * b + 221 * c;
                if (n == m)
                return 100 * a + 10 * b + c;
            }
        }
    }
    return -1;
}
