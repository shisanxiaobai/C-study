#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int b, b0, b1, b2 ;
    printf("Input b: ");
    scanf("%d",&b);
    b = fabs(b);
    b2 = b / 100;
    b1 = (b - b2 * 100) / 10;
    b0 = b % 10;
    printf("b2 = %d, b1 = %d, b0 = %d\n", b2, b1, b0);
    printf("b0 * 100 + b1 * 10 + b2 = %d\n", b0 * 100 + b1 * 10 + b2);
    return 0;
}
