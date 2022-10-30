#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n = 0;
    for (t = 0; t <= 20 * 7; t++)
    {
        if (t <= 20 * 5 && t % 5 == 0)
        {
            n++;
            continue;
        }
        if (t <= 20 * 6 && t % 6 == 0)
        {
            n++;
            continue;
        }
        if (t % 7 == 0)
        {
            n++;
        }
    }
    printf("n = %d\nt = %d\n", n, t-1);
    return 0;
}
