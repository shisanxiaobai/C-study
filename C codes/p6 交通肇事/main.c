#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, a, b, c, d;
    for (i = 5; i < 100; i++)
    {
        for (a = 0; a < 10; a++)
        {
            b = a;
            for (c = 0; c < 10; c++)
            {
                d = c;
                if (c != a && i * i == a * 1000 + b * 100 + c * 10 + d)
                {
                    printf("License plate number :%d%d%d%d\n", a, b, c, d);
                    printf("i = %d\n", i);
                }
            }
        }
    }
    return 0;
}
