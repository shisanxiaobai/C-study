#include <stdio.h>
#include <stdlib.h>

int main()
{
    int give, i;
    float n = 1.0, receive = 0;
    for (i = 1; i <= 30; i++)
    {
        give = 10 * i;
        receive = receive + n;
        n *= 2;
    }
    printf("give = %d ��Ԫ receive = %.4f ��Ԫ\n", give, receive / 1000000.0);
    return 0;
}
