#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

void Transpose(int *a,int *b, int m, int n);
void InputMatrix(int *a, int m, int n);
void PrintMatrix(int *b, int m, int n);

int main()
{
    int a[M][N], b[N][M];
    int m, n;
    printf("Input m:");
    scanf("%d", &m);
    printf("Input n:");
    scanf("%d", &n);
    InputMatrix(*a, m, n);
    Transpose(*a, *b, m, n);
    printf("The transpose matrix is: \n");
    PrintMatrix(*b, m, n);
    return 0;
}

void Transpose(int *a, int *b, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[j * m + i] = a[i * n + j];
        }
    }
}

void InputMatrix(int *a, int m, int n)
{
    int i, j;
    printf("Please input %d * %d matrix:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i * n + j]);
        }
    }
}

void PrintMatrix(int *b, int m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", b[i * m + j]);
        }
        printf("\n");
    }
}
