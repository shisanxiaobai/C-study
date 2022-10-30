#include <stdio.h>
#include <stdlib.h>

void ReadDate(int a[], int n);
void MaxMinExhange(int a[], int n);
void PrintDate(int a[], int n);
void Swap(int *x, int *y);

int main()
{
    int a[10];
    int n;
    printf("Input n(n<=10):");
    scanf("%d", &n);
    printf("Please input %d integer\n", n);
    ReadDate(a, n);
    MaxMinExhange(a, n);
    PrintDate(a, n);
    return 0;
}

void ReadDate(int a[], int n)
{

    int i;
    for (i = 0; i < n; i++)
    {
        printf("Please enter number:");
        scanf("%d", &a[i]);
    }
}

void MaxMinExhange(int a[], int n)
{
    int i;
    int max = a[0], min = a[0];
    int maxpos = 0, minpos = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxpos = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            minpos = i;
        }
    }
    Swap(&a[maxpos], &a[minpos]);
}

void PrintDate(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
