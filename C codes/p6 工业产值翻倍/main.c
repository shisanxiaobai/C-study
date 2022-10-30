#include <stdio.h>
#include <stdlib.h>
#define CURRENT 100

int main()
{
    int year = 0;
    double growrate, output = CURRENT;
    printf("Please input grow rate:");
    scanf("%lf", &growrate);
    do
    {
        output = output * (1 + growrate);
        year++;
    }while (output < 2 * CURRENT);
    printf("when grow rate is %.0f%%, the output can be doubled after %d year.\n", growrate * 100, year);
    return 0;
}
