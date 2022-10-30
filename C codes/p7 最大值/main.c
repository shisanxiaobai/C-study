#include <stdio.h>
#include <stdlib.h>

int MaxNumber(int a, int b);

int main()
{
    int a, b;
    printf("Please enter a and b: ");
    scanf("%d%*c%d", &a, &b);
    MaxNumber(a, b);
    printf("Max number:%d\n",MaxNumber(a, b));
    return 0;
}

int MaxNumber(int a,int b)
{
   return a > b ? a : b;
}
