#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int year;
    double principal,rate,deposit;
    printf("please enter the principal and storage life: ");
    scanf("%lf%*c%d", &principal, &year);
    switch(year)
    {
        case 1:
            rate = 0.0225;
            break;
        case 2:
            rate = 0.0243;
            break;
        case 3:
            rate = 0.0270;
            break;
        case 5:
            rate = 0.0288;
            break;
        case 8:
            rate = 0.0300;
        default:
            printf("This information does not exist\n");
            exit(0);
    }
    deposit = principal * pow(1+rate, year);
    printf("your deposit is %f", deposit);
    return 0;
}
