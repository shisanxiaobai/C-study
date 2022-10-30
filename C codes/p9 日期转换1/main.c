#include <stdio.h>
#include <stdlib.h>

int DayofYear(int year, int month, int day);
int DayTab[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main()
{
    int year, month, day;
    int yearday;
    printf("Input year, month, day:");
    scanf("%d%*c%d%*c%d", &year, &month, &day);
    yearday = DayofYear(year, month, day);
    printf("YearDay = %d", yearday);
    return 0;
}

int DayofYear(int year, int month, int day)
{
    int i;
    int leap;
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    for (i = 1; i < month; i++)
    {
        day += DayTab[leap][i];
    }
    return  day;
}
