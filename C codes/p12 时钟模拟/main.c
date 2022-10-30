#include <stdio.h>
#include <stdlib.h>

typedef struct clock
{
    int hour;
    int min;
    int sec;
}CLOCK;

void Update(CLOCK *t)
{
    t -> sec++;
    if (t -> sec == 60)
    {
        t -> sec = 0;
        t -> min++;
    }
    if (t -> min == 60)
    {
        t -> min = 0;
        t -> hour++;
    }
    if (t -> hour == 24)
    {
        t -> hour = 0;
    }
}

void Display(CLOCK *t)
{
    printf("%02d:%02d:%02d\r",t -> hour, t -> min, t -> sec);
}

void Delay(void)
{
    long t;
    for (t = 0; t < 500000000; t++)
    {

    }
}

int main()
{
    long i;
    CLOCK myclock;
    myclock.hour = myclock.min = myclock.sec = 0;
    for (i = 0; i < 100000; i++)
    {
        Update(&myclock);
        Display(&myclock);
        Delay();
    }
    return 0;
}
