#include <stdio.h>
#include <stdlib.h>
#define N 20

void DataSort(int a[], int n);
void Insert(int a[], int n, int x);

int main()
{
    int i, n, x;
    int a[N + 1];
    printf("Input array size :");
    scanf("%d", &n);
    printf("Please input the element of array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    DataSort(a, n);
    printf("Please input X:");
    scanf("%d", &x);
    Insert(a, n, x);
    printf("After insert %d\n", x);
    for (i = 0; i < n + 1; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

void DataSort(int a[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
            if (k != i)
            {
                temp = a[i];
                a[i] = a[k];
                a[k] = temp;
            }

    }
}

void Insert(int a[], int n, int x)
{
    int i = 0;
    int pos;
    while (i < n && x > a[i])
    {
        i++;
    }
    pos = i;
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = x;
}
