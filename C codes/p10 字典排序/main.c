#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SortString(char country[][10], int n);

int main()
{
    char country[100][10];
    int n, i;
    printf("How many countries?\n");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Please input the name of county:");
        gets(country[i]);
    }
    SortString(country, n);
    printf("Sorted results:\n");
    for (i = 0; i < n; i++)
    {
        puts(country[i]);
    }
    return 0;
}

void SortString(char country[][10], int n)
{
    int i, j;
    char temp[10];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(country[i], country[j]) > 0)
            {
             strcpy(temp, country[i]);
             strcpy(country[i], country[j]);
             strcpy(country[j], temp);
            }
        }

    }
}
