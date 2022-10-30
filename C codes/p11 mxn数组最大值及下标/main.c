#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

void InputArray(int *p, int m, int n);
int FindMax(int *p, int m, int n, int *pRow, int *pCol);

int main()
{
    int a[M][N];
    int m, n;
    int max;
    int row, col;
    printf("Input m:");
    scanf("%d", &m);
    printf("Input n:");
    scanf("%d", &n);
    InputArray(*a, m, n);
    max = FindMax(*a, m, n, &row, &col);
    printf("max number:%d, row:%d, col:%d", max, row, col);
    return 0;
}

void InputArray(int *p, int m, int n)
{
    int i, j;
    printf("Please input %d * %d element:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[i * n + j]);
        }
    }
}

int FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    int i, j;
    int max = p[0];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i * n + j] > max)
            {
                max = p[i * n + j];
                *pRow = i;
                *pCol = j;
            }
        }
    }
    return max;
}
