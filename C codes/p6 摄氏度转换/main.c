#include <stdio.h>
#include <stdlib.h>

int main()
{
    int F;
    float C;
    for (F = 0; F <= 300; F += 10)
    {
        C = 5.0 / 9.0 * (F - 32);
        printf("%4d¡æ\t%5.1f¨H\n", F, C);
    }

    return 0;
}
