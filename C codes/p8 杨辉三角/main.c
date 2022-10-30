#include <stdio.h>
#include <stdlib.h>
#define N 20

void Caculate(int a[][N], int n);
void printYH(int a[][N], int n);

int main()
{
    int n;
    int a[][N] = {{0},{0}};
    printf("input n(n < 20):");
    scanf("%d", &n);
    Caculate(a, n);
    printYH(a, n);
    return 0;
}

void Caculate(int a[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (i = 2; i < n; i++)
    {
        for (j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
}

void printYH(int a[][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", a[i][j]);
            printf("\n");
    }

}
