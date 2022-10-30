#include <stdio.h>
#include <stdlib.h>

main()
{
    const double PI = 3.14159;
    double r;
    printf("Input r : ");
    scanf("%lf", &r);
    printf("c = %f\n", 2*PI*r);
    printf("s = %f\n", PI*r*r);

}
