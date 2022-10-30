#include <stdio.h>
#include <stdlib.h>
#define N 10

void InputMatrix(int a[N][N], int n);
int AddDiagonal(int a[N][N], int n);

int main()
{
    int n, sum;
    int a[N][N];
    printf("Please input n:");
    scanf("%d", &n);
    InputMatrix(a, n);
    sum = AddDiagonal(a, n);
    printf("Diagonal sum = %d\n", sum);
    return 0;
}

void InputMatrix(int a[N][N], int n)
{
    int i, j;
    printf("Input %d * %d matrix:\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int AddDiagonal(int a[N][N], int n)
{
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}
