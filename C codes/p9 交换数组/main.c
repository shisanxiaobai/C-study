#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y);

int main()
{
    int a[2] = {5, 12};
    printf("%d %d\n", a[0], a[1]);
    Swap(&a[0], &a[1]);
    printf("%d %d\n", a[0], a[1]);
    return 0;
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
