#include <stdio.h>
#include <stdlib.h>

#define N 10

void Swap(int *x, int *y);
void Transpose(int a[][N], int n);
void InputMatrix(int a[][N], int n);
void PrintMatrix(int a[][N], int n);

int main()
{
    int a[N][N];
    int n;
    printf("Input n:");
    scanf("%d", &n);
    InputMatrix(a, n);
    Transpose(a, n);
    printf("The transpose matrix is: \n");
    PrintMatrix(a, n);
    return 0;
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Transpose(int a[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            Swap(&a[i][j], &a[j][i]);
        }
    }
}

void InputMatrix(int a[][N], int n)
{
    int i, j;
    printf("Please input %d * %d matrix:\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void PrintMatrix(int a[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
