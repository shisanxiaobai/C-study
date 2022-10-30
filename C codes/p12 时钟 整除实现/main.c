#include <stdio.h>
#include <stdlib.h>

typedef struct clock
{
    int hour;
    int min;
    int sec;
}CLOCK;

void Update(CLOCK *p)
{
    static long m = 1;
    p -> hour = m / 3600;
    p -> min = (m - 3600 * p -> hour) / 60;
    p -> sec  = m % 60;
    m++;
    if (p -> hour == 24)
    {
        m = 1;
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
