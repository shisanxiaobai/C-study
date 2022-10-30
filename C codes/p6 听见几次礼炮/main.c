#include <stdio.h>
#include <stdlib.h>

int hour, minute, second;
void Update();
void Display();
void Delay();


int main()
{
    int i;
    hour = minute = second = 0;
    for (i = 0; i < 10000000; i++)
    {
        Update();
        Display();
        Delay();
    }
    return 0;
}

void Update()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    if (hour == 24)
    {
        hour = 0;
    }
}

void Display()
{
    printf("%2d:%2d:%2d", hour, minute, second);
}

void Delay()
{
    int t;
    for (t = 0; t < 1000000; t++);
}
