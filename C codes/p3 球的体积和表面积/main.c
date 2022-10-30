#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI = 3.14159;
    double r;
    printf("Input r : ");
    scanf("%lf", &r);
    printf("volume = %lf", 4.0 / 3.0 * PI * r * r * r );
    printf("surface area = %lf", 4 * PI * r * r);
    return 0;
}
