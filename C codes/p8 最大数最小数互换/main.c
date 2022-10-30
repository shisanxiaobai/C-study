#include <stdio.h>
#include <stdlib.h>

void ReadInteger(int a[]);
int FindMaxNum(int a[], int n);
int FindMinNum(int a[], int n);
void Exchange (int a[], int n);


int main()
{
    int i;
    int a[10];
    ReadInteger(a);
    Exchange(a, 10);
    printf("Exchange results:");
    for (i = 0; i < 10; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

void ReadInteger(int a[])
{
    int i;
    printf("Input 10 numbers:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
}

void Exchange(int a[], int n)
{
    int maxpos, minpos, temp;
    maxpos = FindMaxNum(a, 10);
    minpos = FindMinNum(a, 10);
    temp = a[maxpos];
    a[maxpos] = a[minpos];
    a[minpos] = temp;
}


int FindMaxNum(int a[], int n)
{
    int i, pos = 0;
    int max = a[0];
    for (i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}


int FindMinNum(int a[], int n)
{
    int i, pos = 0;
    int min = a[0];
    for (i = 0; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}
