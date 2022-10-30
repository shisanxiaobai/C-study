#include <stdio.h>
#include <stdlib.h>
#define RATE 0.01875
#define MONTH 12
#define YEAR 5
#define CAPITAL 1000

int main()
{
    int i;
    double deposit = 0;
    for (i = 1; i <= YEAR; i++)
    {
        deposit = (deposit + CAPITAL) / (1 + MONTH * RATE);
    }
    printf("He must save %.2f at the first year .\n", deposit);

    return 0;
}
