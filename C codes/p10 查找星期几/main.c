#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int flag = 0;
    int pos;
    char find[10];
    char weekDay[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Please input the day of the week you are looking for:");
    scanf("%s", find);
    for (i = 0; i < 7; i++)
    {
        if (strcmp(find, weekDay[i]) == 0)
        {
            flag = 1;
            pos = i;
        }
    }
    if (flag)
    {
        printf("%s is %d\n", find, pos);
    }
    else
    {
        printf("Not found!\n");
    }
    return 0;
}
