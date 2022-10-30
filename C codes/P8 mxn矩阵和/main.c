#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

void InputMatrix(int a[ROW][COL], int m, int n);
void AddMatrix(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL], int m, int n);
void printMatrix (int a[ROW][COL], int m, int n);

int main()
{
    int m, n;
    int a[ROW][COL], b[ROW][COL], c[ROW][COL];
    printf("Input m, n:");
    scanf("%d%*c%d", &m, &n);
    printf("Input %d * %d matrix a:\n", m, n);
    InputMatrix(a, m, n);
    printMatrix(a, m, n);
    printf("input %d * %d matrix b:\n", m, n);
    InputMatrix(b, m, n);
    printMatrix(b, m, n);
    AddMatrix(a, b, c, m, n);
    printf(" c ");
    printMatrix(c, m ,n);
    return 0;
}

void InputMatrix(int a[ROW][COL], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void AddMatrix(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int a[ROW][COL], int m, int n)
{
    int i, j;
    printf("matrix :\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
