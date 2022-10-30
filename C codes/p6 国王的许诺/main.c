#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*利用前后项关系
int main()
{
    int gred;
    double n = 1, sum = 0;
    double grain;
    for (gred = 1; gred <= 64; gred++)
    {
        sum = sum + n;
        n = n * 2;
    }
    grain = sum / 1.42e8;
    printf("The king need %e wheats give his prime minister\n", sum);
    printf("wheat's has %e grain\n", grain);
    return 0;
}
*/
//利用通项
int main()
{
    const double VOLUME = 1.42e8;
    int gred;
    double grain, sum = 0, n;
    for (gred = 1; gred <= 64; gred++)
    {
        n = pow(2, gred - 1);
        sum = sum + n;
    }
    grain = sum / VOLUME;
    printf("need %e wheats\n", sum);
    printf("%e grain\n", grain);
    return 0;
}
