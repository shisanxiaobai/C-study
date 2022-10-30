#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    double rate, capital, deposit;
    printf("please enter rate, year, capital:");
    scanf("%lf, %d, %lf", &rate, &n, &capital);
    deposit = capital * pow(1 + rate, n);
    printf("deposit = %lf\n", deposit);
    return 0;
}
