#include <stdio.h>
#include <stdlib.h>

int DayTab[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
void MonthDay(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year, month, day;
    int yearday;
    printf("Please input year and YearDay:");
    scanf("%d%*c%d", &year, &yearday);
    MonthDay(year, yearday, &month, &day);
    printf("%5dYear%5dMonth%5dDay\n", year, month, day);
    return 0;
}

void MonthDay(int year, int yearday, int *pmonth, int *pday)
{
    int i;
    int leap;
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    for (i = 1; yearday > DayTab[leap][i]; i++)
    {
        yearday -= DayTab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
