#include <stdio.h>
#include <stdlib.h>

#define N 10

void Swap(int *x, int *y);
void Transpose(int *a, int n);
void InputMatrix(int *a, int n);
void PrintMatrix(int *a, int n);

int main()
{
    int a[N][N];
    int n;
    printf("Please input n:");
    scanf("%d", &n);
    InputMatrix(*a, n);
    Transpose(*a, n);
    PrintMatrix(*a, n);
    return 0;
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Transpose(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            Swap(&a[i * n + j], &a[j * n + i]);
        }
    }
}

void InputMatrix(int *a, int n)
{
    int i, j;
    printf("Please input matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i * n + j]);
        }
    }
}

void PrintMatrix(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i * n + j]);
        }
        printf("\n");
    }
}

