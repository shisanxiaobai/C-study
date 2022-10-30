#include <stdio.h>
#include <stdlib.h>

int DayTab[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int Menu(void);
int DayofYear(int year, int month, int day);
void MonthDay(int year, int yearday, int *pmonth, int *pday);


int main()
{
    int year, month, day;
    int yearday;
    int select;
    select = Menu();
    switch (select)
    {
    case 1:
        printf("Please input year, month and day:");
        scanf("%d%*c%d%*c%d", &year, &month, &day);
        yearday = DayofYear(year, month, day);
        printf("YearDay = %d", yearday);
        break;
    case 2:
        printf("Please enter Year and YearDay:");
        scanf("%d%*c%d", &year, &yearday);
        MonthDay(year, yearday, &month, &day);
        printf("%5dÄê%5dÔÂ%5dÈÕ\n", year, month, day);
        break;
    case 3:
        printf("Over program!\n");
        exit(0);
    default:
        printf("Input error\n");
     }
    return 0;
}

int Menu(void)
{
    int select;
    printf("\n1.year/month/day -> yearDay\n");
    printf("2.yearDay -> year/month/day\n");
    printf("3.Exit\n");
    scanf("%d", &select);
    return select;
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
    return day;
}

void MonthDay(int year, int yearday, int *pmonth, int *pday)
{
    int i;
    int leap;
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    for (i = 1; DayTab[leap][i] < yearday; i++)
    {
        yearday -= DayTab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
