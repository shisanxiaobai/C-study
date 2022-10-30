#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char name[10];
    char sex[6];
    DATA birthday;
    struct profession state;
}DATA;

typedef struct date
{
    int year;
    int month;
    int day;
}DATE;

struct profession
{
    char college[20];
    char position[20];
    char job [20];
};



