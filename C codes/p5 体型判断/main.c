#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float t, h, w;
    printf("please input your height and weight: ");
    scanf("%f, %f", &h, &w);
    t = w / (h * h);
    if(t < 18)
    {
        printf("your weight is lower\n");
    }
    else if(t <= 25)
    {
        printf("your weight is normal\n");
    }
    else if(t <= 27)
    {
        printf("your weight is over\n");
    }
    else if(t > 27)
    {
        printf("you are fat\n");
    }
    printf("t = %0.1f\n", t);
    return 0;
}
