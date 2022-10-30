#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MinStr(char country[][10], int n);

int main()
{
    char country[100][10];
    int n, i;
    int minpos;
    printf("How many countries?\n");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Please input the name of county:");
        gets(country[i]);
    }
    minpos = MinStr(country, n);
    printf("Top country:%s\n", country[minpos]);
    return 0;
}

int MinStr(char country[][10], int n)
{
    int i, minpos = 0;
    char min[10];
    strcpy(min, country[0]);
    for (i = 1; i < n; i++)
    {
        if (strcmp(country[i], min) < 0)
        {
            strcpy(min, country[i]);
            minpos = i;
        }
    }
    return minpos;
}
