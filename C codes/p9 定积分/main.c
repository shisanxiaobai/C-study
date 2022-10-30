#include <stdio.h>
#include <stdlib.h>

float Integral(float (*f)(float), float a, float b);
float Fun1(float x);
float Fun2(float x);

int main()
{
    float y1, y2;
    y1 = Integral(Fun1, 0.0, 1.0);
    y2 = Integral(Fun2, 0.0, 3.0);
    printf("y1 = %f\ny2 = %f\n", y1, y2);
    return 0;
}

float Integral(float (*f)(float), float a, float b)
{
    float s, h;
    int n = 100;
    int i;
    s = ((*f)(a) + (*f)(b)) / 2;
    h = (b - a) / 100;
    for (i = 1; i < n; i++)
    {
        s += (*f)(a + i * h);
    }
    return s * h;
}

float Fun1(float x)
{
    return 1 + x * x;
}

float Fun2(float x)
{
    return x / (1 + x * x);
}
