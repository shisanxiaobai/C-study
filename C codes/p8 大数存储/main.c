#include <stdio.h>
#include <stdlib.h>
#define SIZE 51

int BigFact(int data[], int n);

int main()
{
    int data[SIZE] = {0};
    int index;
    int n;
    int i, j;
    printf("Please input n:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        index = BigFact(data, i);
        if (index)
        {
            printf("%d!=", i);
            for (j = index; j > 0; j--)
            {
                printf("%d", data[j]);
            }
            printf("\n");
        }
        else
        {
            printf("Overflow!\n");
            exit(1);
        }
    }
    return 0;
}

int BigFact(int data[], int n)
{
    int i, j, k;
    int index = 1;
    /*for (i = 0; i < SIZE; i++)
    {
        data[i] = 0;
    }*/
    data[1] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= index; j++)
        {
            data[j] = data[j] * i;
        }
        for (k = 1; k < index; k++)
        {
            if (data[k] >= 10)
            {
                data[k + 1] = data[k + 1] + data[k] / 10;
                data[k] = data[k] % 10;
            }
        }
        while (data[index] >= 10 && index <= SIZE - 1)
        {
            data[index + 1] = data[index] / 10;
            data[index] = data[index] % 10;
            index++;
        }
    }
    if (index <= SIZE - 1)
    {
        return index;
    }
    else
        return 0;
}
